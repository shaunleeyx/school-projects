// S. Lee
//11/14/2018
//version 1
//2.data processed is integers and it filters out prime numbers
//3.all numbers can work except bigger than what a int can hold
//4.The UI is very easy to use I made the array type in the flushQ class and made it so the user doesn't even have to deal with the array data all you have to do is insert integers
//5.remove only removes the root, client's only responsiblity is to pass in integers.
//6. I used iostreams and namespace std
//Driver 1.Intend of the driver is to satisify the clients needs of the utility of insertion,remove max,and flush
//       2.data type used in flushQ is a dynamic array
//Classes data types 1.data type is array
//2.root is always the biggest number
//3.a.i.) int n is number of elements in the array, size is the size of the array, and array is the array
// ii.)insert,remove,heapify,heapifydown,printall,isempty,flush,resize,copy constructor
//iv.)n,size,array array depends on size and n
//User can choose to insert data into the heap and choose to remove the largest value,remove all numbers divisible by x, and remove which pops the biggest number and prints it out
#include <iostream>
#include "flushQ.h"
using namespace std;
int main() {
   flushQ Q;
   Q.insert(1);
   flushQ Q2;
   Q2 = Q;
   Q2.printall();

    return 0;
}