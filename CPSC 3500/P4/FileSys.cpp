// CPSC 3500: File System
// Implements the file system commands that are available to the shell.

#include <cstring>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

//other included libraries
#include <stdio.h>
#include <string.h>
#include <unistd.h>
using namespace std;

#include "FileSys.h"
#include "BasicFileSys.h"
#include "Blocks.h"

// mounts the file system
void FileSys::mount(int sock) {
	bfs.mount();
	curr_dir = 1; //by default current directory is home directory, in disk block #1
	fs_sock = sock; //use this socket to receive file system operations from the client and send back response messages
}

// unmounts the file system
void FileSys::unmount() {
	bfs.unmount();
	close(fs_sock);
}

// make a directory
void FileSys::mkdir(const char *name)
{
	string s;
	struct dirblock_t temp;
	short newBlock = bfs.get_free_block();

	if (strlen(name) > MAX_FNAME_SIZE) {
		s = "504 File name is too long\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	bfs.read_block(curr_dir, (void *)&temp);

	for (int i = 0; i < temp.num_entries; i++) {
		if (strcmp(temp.dir_entries[i].name, name) == 0) {
			s = "502 File exists\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
			send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
			return;
		}
	}

	if (temp.num_entries == MAX_DIR_ENTRIES) {
		s = "506 Directory is full\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	if (newBlock == 0) {
		s = "505 Disk is full\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	// if no errors
	unsigned int index = temp.num_entries;
	struct dirblock_t dirblock;

	dirblock.magic = DIR_MAGIC_NUM;
	dirblock.num_entries = 0;

	for (int i = 0; i < MAX_DIR_ENTRIES; i++) {
		dirblock.dir_entries[i].block_num = 0;
	}

	bfs.write_block(newBlock, (void *)&dirblock);

	temp.dir_entries[index].block_num = (int)newBlock;
	strcpy(temp.dir_entries[index].name, name);
	temp.num_entries++;

	bfs.write_block(curr_dir, (void *)&temp);

	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()), 0);
}

// switch to a directory
void FileSys::cd(const char *name)
{
	string s;
	bool notExist = true;
	unsigned int blockNum = 0;
	struct dirblock_t dirblock;

	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		struct dirblock_t temp;
		bfs.read_block(dirblock.dir_entries[i].block_num, (void *)&temp);

		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			if (temp.magic == INODE_MAGIC_NUM) {
				s = "500 File is not a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			else {
				notExist = false;
				blockNum = dirblock.dir_entries[i].block_num;
			}
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
	}
	else {
		curr_dir = blockNum;
	}
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// switch to home directory
void FileSys::home() {
	string s;
	curr_dir = 1;
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// remove a directory
void FileSys::rmdir(const char *name)
{
	string s;
	bool notExist = true;
	unsigned int blockNum = 0;
	struct dirblock_t dirblock;

	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		struct dirblock_t temp;
		bfs.read_block(dirblock.dir_entries[i].block_num, (void *)&temp);
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			if (temp.magic == INODE_MAGIC_NUM) {
				s = "500 File is not a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			else {
				if (temp.num_entries != 0) {
					s = "507 Directory is not empty\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
					send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
					return;
				}
				else {
					notExist = false;
					blockNum = dirblock.dir_entries[i].block_num;

				}
			}
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
	}
	else if (blockNum != 0) {
		int k = 0;
		struct dirblock_t newBlock;

		newBlock.magic = DIR_MAGIC_NUM;
		newBlock.num_entries = (dirblock.num_entries - 1);

		for (int i = 0; i < newBlock.num_entries; i++) {
			if (dirblock.dir_entries[i].block_num == blockNum) {
				k++;
			}
			newBlock.dir_entries[i].block_num = dirblock.dir_entries[k].block_num;
			strcpy(newBlock.dir_entries[i].name, dirblock.dir_entries[k].name);
			k++;
		}

		for (int j = newBlock.num_entries; j < MAX_DIR_ENTRIES; j++) {
			newBlock.dir_entries[j].block_num = 0;
		}

		bfs.write_block(curr_dir, (void *)&newBlock);
		bfs.reclaim_block(blockNum);
	}
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// list the contents of current directory
void FileSys::ls()
{
	string s;
	struct dirblock_t dirblock;
	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		struct dirblock_t temp;
		bfs.read_block(dirblock.dir_entries[i].block_num, (void *)&temp);
		if (temp.magic == DIR_MAGIC_NUM) {
			s = s + dirblock.dir_entries[i].name + "/\n";
		}
		else {
			s = s + dirblock.dir_entries[i].name + "\n";
		}
	}
	int msize = strlen(s.c_str());
	s = "200 OK\\r\\n\nLength: " + to_string(msize) + "\\r\\n\n\\r\\n\n" + s;
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// create an empty data file
void FileSys::create(const char *name)
{
	string s;
	struct dirblock_t dirblock;
	short newBlock = bfs.get_free_block();

	if (strlen(name) > MAX_FNAME_SIZE) {
		s = "504 File name is too long\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	bfs.read_block(curr_dir, (void *)&dirblock);
	unsigned int index = dirblock.num_entries;
	if (index == MAX_DIR_ENTRIES) {
		s = "506 Directory is full\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			s = "502 File exists\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
			send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
			return;
		}
	}

	if (newBlock == 0) {
		s = "505 Disk is full\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	struct inode_t inode;
	inode.magic = INODE_MAGIC_NUM;
	inode.size = 0;

	for (int i = 0; i < MAX_DATA_BLOCKS; i++) {
		inode.blocks[i] = 0;
	}

	bfs.write_block(newBlock, (void *)&inode);
	dirblock.dir_entries[index].block_num = newBlock;
	strcpy(dirblock.dir_entries[index].name, name);
	dirblock.num_entries++;
	bfs.write_block(curr_dir, (void *)&dirblock);
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

void FileSys::append(const char *filename, const char *data)
{
	string s;
	struct dirblock_t dirblock;

	bool notExist = true;
	unsigned int index = 0;
	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, filename) == 0) {
			struct dirblock_t dircheck;
			index = dirblock.dir_entries[i].block_num;
			bfs.read_block(index, (void *)&dircheck);
			if (dircheck.magic == DIR_MAGIC_NUM) {
				s = "501 File is a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			notExist = false;
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	struct inode_t inodeblock;

	short inode_block_num;

	bfs.read_block(curr_dir, (void *)&dirblock);
	for (int i = 0; i < MAX_DIR_ENTRIES; i++) { // scan for the inode's block_num
		if (dirblock.dir_entries[i].block_num != 0 && strcmp(filename, dirblock.dir_entries[i].name) == 0) {
			inode_block_num = dirblock.dir_entries[i].block_num;
		}
	}

	bfs.read_block(inode_block_num, (void *)&inodeblock);

	int touched_blocks[MAX_DATA_BLOCKS]; // blocks that were created
	int touched_blocks_counter = 0; // created blocks counter
	short free_block;
	int current_data_block;
	int current_index;
	int data_index_tracker = 0;
	bool error = false;
	struct datablock_t datablock;

	for (int i = 0; i < strlen(data); i++) {
		current_data_block = inodeblock.size / BLOCK_SIZE; // find which data block the size is pointing
		if (current_data_block >= MAX_DATA_BLOCKS) { // check is data block does not go out max file size
			s = "508 Append exceeds maximum file size\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
			error = true;
			send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
			break;
		}
		if (inodeblock.blocks[current_data_block] == 0) { // check if the current_data_block has a real block
			free_block = bfs.get_free_block(); // gets free block
			if (free_block == 0) { // checks if disk is full
				s = "505 Disk is full\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				error = true;
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				break;
			}
			else {
				touched_blocks[touched_blocks_counter] = free_block;
				touched_blocks_counter++;
				inodeblock.blocks[current_data_block] = free_block; // points to the real block
			}
		}

		current_index = inodeblock.size % BLOCK_SIZE;

		if (current_index == 0) {
			datablock.data[current_index] = data[data_index_tracker];
			inodeblock.size++;;
			data_index_tracker++;
			bfs.write_block(inodeblock.blocks[current_data_block], (void *)&datablock);
		}
		else {
			bfs.read_block(inodeblock.blocks[current_data_block], (void *)&datablock);
			datablock.data[current_index] = data[data_index_tracker];
			inodeblock.size++;
			data_index_tracker++;
			bfs.write_block(inodeblock.blocks[current_data_block], (void *)&datablock);
		}
	}
	if (error) {
		for (int k = 0; k < touched_blocks_counter; k++) {
			bfs.reclaim_block(touched_blocks[k]);
		}
	}
	else {
		bfs.write_block(inode_block_num, (void *)&inodeblock);
	}
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// display the contents of a data file
void FileSys::cat(const char *name)
{
	string s;
	bool notExist = true;
	unsigned int index = 0;
	struct dirblock_t dirblock;
	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			struct dirblock_t dircheck;
			index = dirblock.dir_entries[i].block_num;
			bfs.read_block(index, (void *)&dircheck);
			if (dircheck.magic == DIR_MAGIC_NUM) {
				s = "501 File is a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			notExist = false;
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	} else {
		s = s + "200 OK\\r\\n\n";
	}

	struct inode_t inode;
	int firstBit = 1;
	int firstBlock = 0;
	datablock_t datablock;

	bfs.read_block(index, (void *)&inode);
	bfs.read_block(inode.blocks[firstBlock], (void *)&datablock);
	s = s + "Length: " + to_string(inode.size) + "\\r\\n\n\\r\\n\n";
	for (int i = 0; i < inode.size; i++) {
		s = s + datablock.data[i];
		firstBit++;
		if (firstBit > BLOCK_SIZE) {
			firstBlock++;
			bfs.read_block(inode.blocks[firstBlock], (void *)&datablock);
			firstBit = 1;
		}
	}
	s = s + "\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// display the first N bytes of the file
void FileSys::head(const char *name, unsigned int n)
{
	string s;
	bool notExist = true;
	unsigned int index = 0;
	struct dirblock_t dirblock;
	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			struct dirblock_t dircheck;
			index = dirblock.dir_entries[i].block_num;
			bfs.read_block(index, (void *)&dircheck);
			if (dircheck.magic == DIR_MAGIC_NUM) {
				s = "501 File is a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			notExist = false;
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	struct inode_t inode;
	int firstBit = 1;
	int firstBlock = 0;
	datablock_t datablock;

	bfs.read_block(index, (void *)&inode);
	bfs.read_block(inode.blocks[firstBlock], (void *)&datablock);
	for (int i = 0; i < (int)n; i++) {
		s = s + datablock.data[i];
		firstBit++;
		if (firstBit > BLOCK_SIZE) {
			firstBlock++;
			bfs.read_block(inode.blocks[firstBlock], (void *)&datablock);
			firstBit = 1;
		}
	}
	int msize = strlen(s.c_str());
	s = "200 OK\\r\\n\nLength: " + to_string(msize) + "\\r\\n\n\\r\\n\n" + s;
	s = s + "\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// delete a data file
void FileSys::rm(const char *name)
{
	string s;
	bool notExist = true;
	int index;
	struct inode_t inode;
	struct dirblock_t dirblock;
	bfs.read_block(curr_dir, (void *)&dirblock);

	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			struct dirblock_t dircheck;
			index = dirblock.dir_entries[i].block_num;
			bfs.read_block(index, (void *)&dircheck);
			if (dircheck.magic == DIR_MAGIC_NUM) {
				s = "501 File is a directory\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
				send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
				return;
			}
			notExist = false;
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	int numBlocks = 0;
	int loop = -1;
	bfs.read_block(index, (void *)&inode);

	do {
		loop = inode.blocks[numBlocks];
		numBlocks++;
		if (loop != 0) {
			struct datablock_t datablock;
			bfs.read_block(inode.blocks[loop], (void *)&datablock);

			for (int i = 0; i < BLOCK_SIZE; i++)
				datablock.data[i] = 0;

			bfs.write_block(inode.blocks[loop], (void *)&datablock);
			bfs.reclaim_block(inode.blocks[loop]);
		}
		inode.blocks[numBlocks] = 0;
	} while (loop > 0);

	inode.size = 0;
	bfs.write_block(index, (void *)&inode);
	bfs.reclaim_block(index);

	int k = 0;
	struct dirblock_t newBlock;

	newBlock.magic = DIR_MAGIC_NUM;
	newBlock.num_entries = (dirblock.num_entries - 1);

	for (int i = 0; i < newBlock.num_entries; i++) {

		if (dirblock.dir_entries[i].block_num == index) {
			k++;
		}
		newBlock.dir_entries[i].block_num = dirblock.dir_entries[k].block_num;
		strcpy(newBlock.dir_entries[i].name, dirblock.dir_entries[k].name);
		k++;
	}

	for (int j = newBlock.num_entries; j < MAX_DIR_ENTRIES; j++)
		newBlock.dir_entries[j].block_num = 0;

	bfs.write_block(curr_dir, (void *)&newBlock);
	s = "200 OK\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// display stats about file or directory
void FileSys::stat(const char *name)
{
	string s;
	bool isDir = false;
	bool notExist = true;
	int index;

	struct dirblock_t dirblock;
	bfs.read_block(curr_dir, (void *)&dirblock);
	for (int i = 0; i < dirblock.num_entries; i++) {
		if (strcmp(dirblock.dir_entries[i].name, name) == 0) {
			index = dirblock.dir_entries[i].block_num;
			struct dirblock_t dircheck;
			bfs.read_block(index, (void *)&dircheck);
			if (dircheck.magic == DIR_MAGIC_NUM) {
				isDir = true;
			}
			notExist = false;
		}
	}

	if (notExist) {
		s = "503 File does not exist\\r\\n\nLength: 0\\r\\n\n\\r\\n\n";
		send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
		return;
	}

	if (isDir) {
		s = s + "Directory name: " + name + "/\n";
		s = s + "Directory block: " + to_string(index) + "\n";
	}
	else {
		int numBlocks = 0;
		int loop = -1;
		struct inode_t statBlock;
		bfs.read_block(index, (void *)&statBlock);
		do {
			loop = statBlock.blocks[numBlocks];
			numBlocks++;
		} while (loop > 0);
		s = s + "Inode block: " + to_string(index) + "\n";
		s = s + "Bytes in file: " + to_string(statBlock.size) + "\n";
		s = s + "Number of blocks: " + to_string(numBlocks) + "\n";
		if (numBlocks < 2) {
			s = s + "First block: 0\n";
		}
		else {
			s = s + "First block: " + to_string(index - numBlocks) + "\n";
		}
	}
	int msize = strlen(s.c_str());
	s = "200 OK\\r\\n\nLength: " + to_string(msize) + "\\r\\n\n\\r\\n\n" + s;
	send(fs_sock, s.c_str(), strlen(s.c_str()) + 1, 0);
}

// HELPER FUNCTIONS (optional)