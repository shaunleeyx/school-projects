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
 *                    reset() resets the obj to default state
 *                    switchstate switches obj active from active to inactive and inactive to active 
 *                    rangeDiv obj generates its prime numbers incrementally so like {2,3,5,7,11,13}
 */
#include "intDiv.h"
#ifndef CLIONPROJECTS_RANGEDIV_H
#define CLIONPROJECTS_RANGEDIV_H

class rangeDiv
{
public:
    rangeDiv(int num = 1);
    ~rangeDiv();
    void test(int num);
    int gettestCount();
    int getremainderCount();
    int getdivisibleCount();
    void switchstate();
    void reset();
    rangeDiv(const rangeDiv &obj);
    rangeDiv(rangeDiv &&obj);
    rangeDiv &operator=(const rangeDiv &obj);
    rangeDiv &operator=(rangeDiv &&obj);
    void operator+=(rangeDiv rhs);
    rangeDiv operator+(rangeDiv rhs);
    rangeDiv operator+(int rhs);
    rangeDiv operator-(int rhs);//a
    void operator+=(int rhs);
    void operator-=(int rhs);
    void operator-=(rangeDiv rhs);
    rangeDiv operator-(rangeDiv rhs);
    bool operator<(rangeDiv rhs); 
    bool operator>(rangeDiv rhs); 
    bool operator==(rangeDiv rhs);
    bool operator!=(rangeDiv rhs); 
    template <typename T>
    void swap(T &lhs, T &rhs);

private:
    bool static isPrime(int num);
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
