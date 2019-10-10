//
// Created by Shaun Lee on 11/7/18.
//

#include "flushQ.h"
#include <iostream>

using namespace std;
//constructor sets arrray size
flushQ::flushQ() {
    array = new int[size + 1];
}
//prints out the entire array
void flushQ::printall() {
    for (int i = 0; i <= n; i++) {
        std::cout << i << ".)" << array[i] << " ";

    }
    cout << endl;
}
//inserts integer into the array as element
void flushQ::insert(int in) {
    bool isPrime = true;
    for (int i = 2; i < in; i++) {
        if (in % i == 0) {
            isPrime = false;

        }

    }
if(isPrime) return;

    n++;
    if (n > size) resize();
    array[n] = in;
    int up = n;
    while (up > 1 && array[up] > array[up / 2]) {
        std::swap(array[up], array[up / 2]);
        up /= 2;
    }

}
//removes the largest number in the array
int flushQ::remove() {
    if (n == 0){
        return -1;
    }
    int local = array[1];
    array[1] = array[n];
    heapifyDown(1);
    n--;
    return local;
}
//swaps the element in the 2 index of the array
void flushQ::swap(int a, int b) {
    int temp;
    temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}
//chooses an index and then compares it with its children and then it moves depending if the children are greater than its parents
void flushQ::heapifyDown(int i) {
    bool done = false;

    while (!done && 2 * i <= n) {

        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;

        if (array[left] > array[i]) largest = left;
        if ((right) <= n && array[right] > array[largest]) largest = right;
        if (largest != i) {
            swap(i, largest);
            i = largest;
        } else done = true;
    }

    return;

}
// see if array is empty
bool flushQ::isEmpty() {
    if (n == 0) return true;
}

//removes all numbers divisible by x in the array
void flushQ::flush(int x) {

    for (int i = 1; i <= n; i++) {

        if (array[i] % x == 0) {
            swap(1, i);
            remove();
        }
    }
    for (int i = 1; i <= n; i++) {

        if (array[i] % x == 0) {
            swap(1, i);
            remove();
        }
    }
    heapify();

}
//does heapifydown to the entire heap
void flushQ::heapify() {
    for(int i = (n)/2; i > 0; i--)
    {
        heapifyDown(i);
    }
    for(int i = (n)/2; i > 0; i--)
    {
        heapifyDown(i);
    }


}

flushQ::flushQ(const flushQ &obj)//copy constructor
{

    n = obj.n;
    array = new int[obj.size * 2];

    for (int i = 0; i < n; i++) {
        array[i] = obj.array[i];
    }
}

flushQ flushQ:: operator+(const flushQ &obj)
{
    flushQ brandnew;
    for (int i = 0; i < n; i++) {
        brandnew.array[i] = obj.array[i];
    }
return brandnew;
}

//resizes the array
void flushQ::resize() {

    int *newarray = new int[size * 2 + 1];
    size *= 2;
    for (int i = 1; i <= n; i++) {
        newarray[i] = array[i];
    }
    delete[] array;
    array = newarray;

}
//destructor
flushQ::~flushQ() {
    delete[] array;
};
