// CPSC 3500: Shell
// Implements a basic shell (command line interface) for the file system

#include <iostream>
#include <fstream>
#include <sstream>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

#include "Shell.h"

static const string PROMPT_STRING = "NFS> ";	// shell prompt

// Mount the network file system with server name and port number in the format of server:port
void Shell::mountNFS(string fs_loc) {
	//create the socket cs_sock and connect it to the server and port specified in fs_loc
  
  if ((cs_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    cout << "client socket failed\n";
    return;
  }

  string host = fs_loc.substr(0, fs_loc.find(":"));
  int port = atoi(fs_loc.substr(fs_loc.find(":") + 1).c_str());

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, host.c_str(), &serv_addr.sin_addr) <= 0) {
    cout << "invalid address\n";
    return;
  }

  if (connect(cs_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) { 
    cout << "connection failed\n";
    return; 
  } 

  is_mounted = true;
  
	//if all the above operations are completed successfully, set is_mounted to true  
}

// Unmount the network file system if it was mounted
void Shell::unmountNFS() {
  // close the socket if it was mounted
  if (is_mounted) {
    close(cs_sock);
  }
}

// Remote procedure call on mkdir
void Shell::mkdir_rpc(string dname) {
  const char * msg = ("mkdir " + dname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on cd
void Shell::cd_rpc(string dname) {
  const char * msg = ("cd " + dname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on home
void Shell::home_rpc() {
  const char * msg = "home\\r\\n";
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on rmdir
void Shell::rmdir_rpc(string dname) {
  const char * msg = ("rmdir " + dname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on ls
void Shell::ls_rpc() {
  const char * msg = "ls\\r\\n";
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  int idx = res.find("\\r\\n", res.find("\\r\\n", res.find("\\r\\n") + 1) + 1) + 5;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    if (res.substr(idx).empty()) {
      cout << "empty folder\n";
    } else {
      cout << res.substr(idx);
    }
  }
}

// Remote procedure call on create
void Shell::create_rpc(string fname) {
  const char * msg = ("create " + fname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on append
void Shell::append_rpc(string fname, string data) {
  const char * msg = ("append " + fname + " " + data + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procesure call on cat
void Shell::cat_rpc(string fname) {
  const char * msg = ("cat " + fname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  int idx = res.find("\\r\\n", res.find("\\r\\n", res.find("\\r\\n") + 1) + 1) + 5;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << res.substr(idx);
  }
}

// Remote procedure call on head
void Shell::head_rpc(string fname, int n) {
  stringstream ss;
  ss << "head " << fname << " " << n << "\\r\\n"; 
  string msg_str = ss.str();
  const char * msg = msg_str.c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  int idx = res.find("\\r\\n", res.find("\\r\\n", res.find("\\r\\n") + 1) + 1) + 5;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << res.substr(idx);
  }
}

// Remote procedure call on rm
void Shell::rm_rpc(string fname) {
  const char * msg = ("rm " + fname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << "success\n";
  }
}

// Remote procedure call on stat
void Shell::stat_rpc(string fname) {
  const char * msg = ("stat " + fname + "\\r\\n").c_str();
  int bytes_sent = send(cs_sock, (void*) msg, strlen(msg), 0);
  if (bytes_sent <= 0) {
    cout << "send failed\n";
    return;
  }
  char buf[1024];
  int bytes_rec = recv(cs_sock, (void*) buf, sizeof(buf), 0);
  if (bytes_rec <= 0) {
    cout << "read failed\n";
    return;
  }
  string res = buf;
  int idx = res.find("\\r\\n", res.find("\\r\\n", res.find("\\r\\n") + 1) + 1) + 5;
  if (res.substr(0, 3) != "200") {
    //error
    cout << res.substr(0, res.find("\\r\\n")) << endl;
  } else {
    cout << res.substr(idx);
  }
}

// Executes the shell until the user quits.
void Shell::run()
{
  // make sure that the file system is mounted
  if (!is_mounted)
 	  return; 
  
  // continue until the user quits
  bool user_quit = false;
  while (!user_quit) {

    // print prompt and get command line
    string command_str;
    cout << PROMPT_STRING;
    getline(cin, command_str);

    // execute the command
    user_quit = execute_command(command_str);
  }

  // unmount the file system
  unmountNFS();
}

// Execute a script.
void Shell::run_script(char *file_name)
{
  // make sure that the file system is mounted
  if (!is_mounted)
  	return;
  // open script file
  ifstream infile;
  infile.open(file_name);
  if (infile.fail()) {
    cerr << "Could not open script file" << endl;
    return;
  }


  // execute each line in the script
  bool user_quit = false;
  string command_str;
  getline(infile, command_str, '\n');
  while (!infile.eof() && !user_quit) {
    cout << PROMPT_STRING << command_str << endl;
    user_quit = execute_command(command_str);
    getline(infile, command_str);
  }

  // clean up
  unmountNFS();
  infile.close();
}


// Executes the command. Returns true for quit and false otherwise.
bool Shell::execute_command(string command_str)
{
  // parse the command line
  struct Command command = parse_command(command_str);

  // look for the matching command
  if (command.name == "") {
    return false;
  }
  else if (command.name == "mkdir") {
    mkdir_rpc(command.file_name);
  }
  else if (command.name == "cd") {
    cd_rpc(command.file_name);
  }
  else if (command.name == "home") {
    home_rpc();
  }
  else if (command.name == "rmdir") {
    rmdir_rpc(command.file_name);
  }
  else if (command.name == "ls") {
    ls_rpc();
  }
  else if (command.name == "create") {
    create_rpc(command.file_name);
  }
  else if (command.name == "append") {
    append_rpc(command.file_name, command.append_data);
  }
  else if (command.name == "cat") {
    cat_rpc(command.file_name);
  }
  else if (command.name == "head") {
    errno = 0;
    unsigned long n = strtoul(command.append_data.c_str(), NULL, 0);
    if (0 == errno) {
      head_rpc(command.file_name, n);
    } else {
      cerr << "Invalid command line: " << command.append_data;
      cerr << " is not a valid number of bytes" << endl;
      return false;
    }
  }
  else if (command.name == "rm") {
    rm_rpc(command.file_name);
  }
  else if (command.name == "stat") {
    stat_rpc(command.file_name);
  }
  else if (command.name == "quit") {
    return true;
  }

  return false;
}

// Parses a command line into a command struct. Returned name is blank
// for invalid command lines.
Shell::Command Shell::parse_command(string command_str)
{
  // empty command struct returned for errors
  struct Command empty = {"", "", ""};

  // grab each of the tokens (if they exist)
  struct Command command;
  istringstream ss(command_str);
  int num_tokens = 0;
  if (ss >> command.name) {
    num_tokens++;
    if (ss >> command.file_name) {
      num_tokens++;
      if (ss >> command.append_data) {
        num_tokens++;
        string junk;
        if (ss >> junk) {
          num_tokens++;
        }
      }
    }
  }

  // Check for empty command line
  if (num_tokens == 0) {
    return empty;
  }
    
  // Check for invalid command lines
  if (command.name == "ls" ||
      command.name == "home" ||
      command.name == "quit")
  {
    if (num_tokens != 1) {
      cerr << "Invalid command line: " << command.name;
      cerr << " has improper number of arguments" << endl;
      return empty;
    }
  }
  else if (command.name == "mkdir" ||
      command.name == "cd"    ||
      command.name == "rmdir" ||
      command.name == "create"||
      command.name == "cat"   ||
      command.name == "rm"    ||
      command.name == "stat")
  {
    if (num_tokens != 2) {
      cerr << "Invalid command line: " << command.name;
      cerr << " has improper number of arguments" << endl;
      return empty;
    }
  }
  else if (command.name == "append" || command.name == "head")
  {
    if (num_tokens != 3) {
      cerr << "Invalid command line: " << command.name;
      cerr << " has improper number of arguments" << endl;
      return empty;
    }
  }
  else {
    cerr << "Invalid command line: " << command.name;
    cerr << " is not a command" << endl; 
    return empty;
  } 

  return command;
}

