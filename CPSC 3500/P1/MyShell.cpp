#include <stdio.h>
#include <unistd.h>     //pid
#include <iostream>     //reading & writing from/to i/o stream
#include <sys/types.h>  //use for wait()
#include <sys/wait.h>   //use for wait()
#include <vector>       //vector to store token list
#include <string.h>     //for c_string char*

using namespace std;
void generate_token_list(string command);
void generate_args_list(int child, vector<char*>token_list);
static vector<char*>token_list;
int command_number = 1;  //total commands

int main(int argc, char **argv){
  cout << "MyShell$ "; //change to my shell later

  string command;
  getline(cin, command);
  if(command.length() > 0){
    generate_token_list(command);
 
  //fd = file descriptor
    int fd[command_number][2];
    int pipe_ends[2];      //create an array of 2 to store the in/out ends of a pipe
    for (int i = 0; i < command_number-1; i++)
    {
    int fail  = pipe(pipe_ends);       //create (command_number)-1 pipe
    if(fail == -1) cout << "Pipe failed.\n";
    
    //for each fd except the last processors
    fd[i][1] = pipe_ends[0];    //set the write of fd to the read end of pipe
    fd[i+1][0] = pipe_ends[1];  //set the read of next fd to the write end of pipe
    }

    pid_t children[10];
    pid_t child_pid;
//fork loop
    for (int i = 0; i < command_number; i++) {  //create n child processes
      int child = i;     //process
      int pid, status;
      child_pid = fork();
      switch(child_pid){
      case -1:   //fork failed
        perror("fork");
        exit(EXIT_FAILURE);
        break;
        case 0:    //child process
        
        int fail;
        //read
        if(child >0){
          fail=dup2(fd[child-1][0],0);
          if(fail == -1) cout << "Dup2 failed\n";
        }//esle,leave it, read from stdin

       //write
        if(child <command_number-1){
          fail = dup2(fd[child][1],1);
          if (fail == -1) cout << "Dup2 failed\n";
        }//else, leave it, write to stdout

        //close
        if(child > 0){
          fail = close(fd[child-1][1]);
          if(fail == -1) cout << "Close failed\n";
          fail = close(fd[child][0]);
          if(fail == -1) cout << "Close failed\n";
       // }else{  //first process
       //   close(fd[child][0]);  //close the unused read end
        }

        //generate args list and call execvp
        generate_args_list(child+1,token_list);
        exit(0);
        break;
        
        default:  //parent process
        for(int i = 0; i < command_number;i++){
          close(fd[i][0]);
          close(fd[i][1]);
        }
        children[child] = child_pid;
        cout << "child "<< child << children[child] << endl;
        pid = wait(&status);
        if(pid != -1){
          printf("got exit of %d\n", WEXITSTATUS(status));
        }
       break;
      }
    }
  }
  return 0;
}
void generate_args_list(int child, vector<char*>token_list){
  //child start at 1
  cout << "generate_arg_list worked!\n";
  int count_pipe = 0;
  int count_arg = 0;
  char* args[50];
  for(int i = 0; i < token_list.size(); i++){
    if(child==count_pipe){ 
      args[count_arg] = token_list[i];
      count_arg++;
    }
    if(strcmp(token_list[i], "|")==0){ 
      count_pipe++; 
    } 
  }
  args[count_arg] = (char*)NULL;
  
  //for(int i = 0; i < count_arg; i++){
  //  cout << args[0] << " ";
  //}cout << endl;

  //execvp(args[0], args);
}
void generate_token_list(string command){     //a pointer to a pointer of a char
    //keep track of all tokens including pipe
  bool quotation_pair = false;  
  char quotation;
  bool token_completed = true;
  char token[100]="";
  command += "\n";

  //build a list of tokens
  for(char &c: command){
	  if((c=='\'' || c=='\"')&&!quotation_pair){
     quotation_pair = true;
     quotation = c;
    }else{
	  	if(isspace(c) &&  !quotation_pair){       //space not inside quotation
        if(!token_completed){
          token_list.push_back(strdup(token));          //add token to token list
          strcpy(token, "");                    //clear token
        }
          token_completed = true;
		  }else if (c=='|' && !quotation_pair){
			  if (!token_completed){ 
          token_list.push_back(strdup(token));
        }
        strcpy(token, "|");
        token_list.push_back(strdup(token));
        strcpy(token, "");
			  token_completed = true;
        command_number++;
		  }else if(c == quotation && quotation_pair){
			  quotation_pair = false;
        token_list.push_back(strdup(token));
        strcpy(token, "");
        token_completed = true;
	  	}else{
        strncat(token, &c,1);
        token_completed = false;
		  }
	  }
  }
  token_list.push_back((char*)NULL);
}