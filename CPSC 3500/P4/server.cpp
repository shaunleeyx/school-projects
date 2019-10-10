#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "FileSys.h"
using namespace std;

void handle_error(string err) {
  perror(err.c_str());
  exit(EXIT_FAILURE);
}

struct Command {
  string name;
  string file;
  string arg;
};

Command parse_command(string msg) {
  msg = msg.substr(0, msg.length() - 4);
  istringstream ss(msg);
  struct Command cmd;
  ss >> cmd.name;
  ss >> cmd.file;
  ss >> cmd.arg;
  return cmd;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Usage: ./nfsserver port#\n";
    return -1;
  }
  int port = atoi(argv[1]);

  //networking part: create the socket and accept the client connection

  int sock = socket(AF_INET, SOCK_STREAM, 0); 
  
  if (sock == -1)
    handle_error("socket failed");

  struct sockaddr_in addr;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = 0;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_family = AF_INET;

  if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1)
    handle_error("bind failed");
  
  if (listen(sock, 25) == -1)
    handle_error("listen failed");

  int req;

  char buf[1024];
  struct sockaddr_in client_addr;
  socklen_t client_addr_size = sizeof(struct sockaddr_in);
  
  if ((req = accept(sock, (sockaddr *) &client_addr, &client_addr_size)) == -1)
    handle_error("accept failed");

  //mount the file system
  FileSys fs;
  fs.mount(req); //assume that sock is the new socket created 
                  //for a TCP connection between the client and the server.   

  //loop: get the command from the client and invoke the file
  //system operation which returns the results or error messages back to the client
  //until the client closes the TCP connection.
  
  int bytes_rec;
  bool cont = true;
  while (cont) {
    bytes_rec = recv(req, (void*) buf, sizeof(buf), 0);
    if (bytes_rec < 0)
      handle_error("read failed");
    if (bytes_rec == 0) {
      cont = false;
    } else {
      string msg = buf;
      Command cmd = parse_command(msg);
      string name = cmd.name;
      if (name == "ls") {
        fs.ls();
      } else if (name == "home") {
        fs.home();
      } else {
        const char * file = cmd.file.c_str();
        if (name == "mkdir") {
          fs.mkdir(file);
        } else if (name == "cd") {
          fs.cd(file);
        } else if (name == "rmdir") {
          fs.rmdir(file);
        } else if (name == "create") {
          fs.create(file);
        } else if (name == "cat") {
          fs.cat(file);
        } else if (name == "rm") {
          fs.rm(file);
        } else if (name == "stat") {
          fs.stat(file);
        } else if (name == "head") {
          fs.head(file, stoi(cmd.arg));
        } else if (name == "append") {
          fs.append(file, cmd.arg.c_str());
        } else {
          cerr << "unknown command";
        }
      }
      memset(buf, 0, sizeof(buf));
    }
  }

  //close the listening socket
  close(req);

  //unmount the file system
  fs.unmount();

  return 0;
}