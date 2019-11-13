/**
 *Author:Shaun Lee
 *Date:11/03/2019
 *Version:v1.2
 *Platform:VSCode
 *
 *Interface Invariant:
 *                    primecount starts at 2
 *                    range encapsulates the number of arrays
 *                    Prime number generator uses a seperate function to return a incrementing prime number example is 3,5,7,11
 *                    Prime number generator uses the isPrime to check if the number is primew
 *                    if input for constructor is negative or 0 then it is 1
 *                    if input for test() is negative or 0 then its 1
 *                    did not implement - operator because it has too much overhead(finding the index and then resizing so the array doesn't have the element)
 */
#include "intDiv.h"
#ifndef CLIONPROJECTS_RANGEDIV_H
#define CLIONPROJECTS_RANGEDIV_H

class rangeDiv
{
public:
    //PRECONDITION:Any number except numbers that won't overflow a integer
    //POSTCONDITION: Instantiation of all fields and intDiv array, input number is the size of array
    rangeDiv(int num = 1);
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
    rangeDiv(const rangeDiv &obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: switch ownership of the obj
    rangeDiv(rangeDiv &&obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: copies to the intialized rangeDiv obj
    rangeDiv &operator=(const rangeDiv &obj);
    rangeDiv &operator=( rangeDiv &&obj);
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: switch ownership of the obj
    
    void  operator+=(rangeDiv rhs);
    rangeDiv operator+(rangeDiv rhs);
    rangeDiv operator+(int rhs);
    void operator-=(rangeDiv rhs);
    rangeDiv operator-(rangeDiv rhs);
    bool operator<(rangeDiv rhs);//compares the range of both rangeDiv objects
    bool operator>(rangeDiv rhs);//compares the range of both rangeDiv objects
    
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
