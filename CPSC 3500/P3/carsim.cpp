#include <stdio.h> 
#include <stdlib.h> 
#include <semaphore.h>
#include <pthread.h>
#include <iostream>
#include <queue>
#include <pthread.h>
#include <time.h>

using namespace std;

struct car{
  int CarID;
  char direction;
  string arrival_time;
  string start_time;
  string end_time;
};

int pthread_sleep(int seconds)
{
    pthread_mutex_t mutex;
    pthread_cond_t conditionvar;
    struct timespec timetoexpire;
    if (pthread_mutex_init(&mutex, NULL))
    {
        return -1;
    }
    if (pthread_cond_init(&conditionvar, NULL))
    {
        return -1;
    }
}

queue<car> northCars, southCars;
sem_t southCount, northCount;
sem_t southLine, northLine;

void* carGenerator(void* args) {
  char dir = ((char*) args)[0];
  if (dir == 'S') {
    cout << "south generator started";
  } else if (dir == 'N') {
    cout << "north generator started";
  }
  return 0;
}

string printTime();
int pthread_sleep(int seconds);

int main() {
  const int countSize = 0;
  const int lineSize = 10;
  sem_init(&southCount, 0, countSize);
  sem_init(&northCount, 0, countSize);
  sem_init(&southLine, 0, lineSize);
  sem_init(&northLine, 0, lineSize);
  pthread_t south, north;
  char s = 'S';
  char n = 'N';

  if ( -1 == pthread_create(&south, NULL, carGenerator, &s) ) {
    perror("pthread_create");
    return -1;
  }

  if ( -1 == pthread_create(&north, NULL, carGenerator, &n) ) {
    perror("pthread_create");
    return -1;
  }
  //TODO: flag person thread below
}

//returns a string with Hours:minute:seconds
string printTime()
{
time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );
  
    strftime(buffer,80,"%I:%M:%S", info);
    string output(buffer);
   return output;
}