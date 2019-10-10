#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <chrono>

using namespace std;
struct PCB {
    int pid;
    int arrivalTime;
    int burstTime;
    int exitTime;
    int waitingTime;
    int remainingTime;
    int responseTime;
};

void readInput(char *argv[]);

void FCFS();

void RR();

void SRTF();

PCB* pcbList;
const int capacity = 100;
int main(int argc, char *argv[])// argv[1] is filename, argv[2] is sched method
{
    auto start = std::chrono::system_clock::now();
    pcbList = new PCB[capacity]; //TODO: change to default
    readInput(argv);//inserts argv[1] to the txtfile
    string argvTwo(argv[2]);//convert char* to string
    if (argvTwo == "FCFS") //reads argv[2] for FCFS/RR/SRTF
    {
        FCFS();
    } else if (argvTwo == "RR") {
        RR();
    } else if (argvTwo == "SRTF") {
        SRTF();
    } else {
        cout << "argv[2] wasn't FCFS/RR/SRTF" << endl;
        return 0;
    }
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start);
    cout << duration1.count() << endl;
    cout << "PROGRAM ENDED SUCCESSFULLY" << endl;
}

void readInput(char *argv[]) {
    ifstream infile(argv[1]);
    int a, b, c, i;
    i = 0;
    while (infile >> a >> b >> c) {// a = pid, b = arrivalTime, c = burstTime
        pcbList[i].pid = a;
        pcbList[i].arrivalTime = b;
        pcbList[i].burstTime = c;
        pcbList[i].exitTime = b;
        pcbList[i].remainingTime = c;
        pcbList[i].waitingTime = 0;
        pcbList[i].responseTime = 0;
        cout << pcbList[i].pid << " " << pcbList[i].arrivalTime << " " << pcbList[i].burstTime << endl;
        i++;
        /*
         * pid = pid;
         arrivaltime = arrival_time;
         bursttime = bursttime;
         exittime = arrivaltime;
         remainingtime = burstime;
         waittime = 0;
         responsetime = 0;
         */
    }
}

void FCFS() {
    cout << "FCFS FUNCTION EXECUTED" << endl;
}

void RR() {
    cout << "RR FUNCTION EXECUTED" << endl;
}

void SRTF() {
    cout << "SRTF FUNCTION EXECUTED" << endl;
}
