
/**
 *Author:Shaun Lee
 *Date:11/03/2019
 *Version:v1.2
 *Platform:Clion C++11
 *Class Overview: this class inputs a number into a bunch of intDiv objects with distinct prime numbers and then counts how many have remainders, how many doesn't, and how many times you inputted a number
 *
 *Class Invariant:Client is given the function switchstate to have on and off state of the functionality of test()
 *                test() doesn't return anything you get your results from the get statements
 *                divisibleCount will increase depending on how many numbers had no remainder everytime you call test()
 *                remainderCount will increase based on how many numbers have remainders everytime you call test()
 *
 *
 *Interface Invariant:primecount starts at 2
 *                    range encapsulates the number of arrays
 */
#include  "intDiv.h"
#ifndef CLIONPROJECTS_RANGEDIV_H
#define CLIONPROJECTS_RANGEDIV_H


class rangeDiv {
public:
    //PRECONDITION:Any number except numbers that won't overflow a integer
    //POSTCONDITION: Instantiation of all fields and intDiv array, input number is the size of array
    rangeDiv(int num);
    ~rangeDiv();
    //PRECONDITION: Any number except numbers that won't overflow a integer
    //POSTCONDITION: testCount will incremented by 1, divisibleCount will increase depending on how many numbers had no remainder, remainderCount will increase based on how many numbers have remainders
    void test(int num);
    //PRECONDITION: none
    //POSTCONDITION: returns testCount
    int gettestCount();
    //PRECONDITION:none
    //POSTCONDITION: returns remainderCount
    int getremainderCount();
    //PRECONDITION:none
    //POSTCONDITION:returns divisibleCount
    int getdivisibleCount();
    //PRECONDITION:none
    //POSTCONDITION:changes the active state from positive to negative and negative to positive
    void switchstate();
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: copies to the intialized rangeDiv obj
    rangeDiv(const rangeDiv& obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: switch ownership of the obj
    rangeDiv(rangeDiv&& obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: copies to the intialized rangeDiv obj
    rangeDiv& operator=(const rangeDiv& obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: switch ownership of the obj
    rangeDiv& operator=(rangeDiv&& obj);

private:
    //PRECONDITION: a int
    //POSTCONDITION: returns true or false depending if its prime
    bool static isPrime(int num);
    //PRECONDITION: none
    //POSTCONDITION: generates a primenumber incrementing upwards 2,3,5,7,11
    unsigned int PrimeNumGen();
    intDiv *arr;
    int range;
    int primecount;
    int divisibleCount;
    int remainderCount;
    int testCount;
    bool active;
};


#endif //CLIONPROJECTS_RANGEDIV_H

