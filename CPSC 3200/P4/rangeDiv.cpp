/*
*Author:Shaun Lee
*Date:11/03/2019
*Version:v1.2
*Platform:VSCode
*
*Class Overview: this class inputs a number into a bunch of intDiv objects with distinct prime numbers and then counts how many have remainders, how many doesn't, and how many times you inputted a number
*
*Implementation invariant: Prime number generator uses a seperate function to return a incrementing prime number example is 3,5,7,11
*                          Prime number generator uses the isPrime to check if the number is primew
*                          if input for constructor is negative or 0 then it is 1
*                          if input for test() is negative or 0 then its 1
*                          if intdiv objects are inactive then test doesn't do anything
*                          testCount is number of times test has been invoked
*                          divisibleCount: the number of its ‘range’ intDiv objects that yield no remainder when testing the divisibility of the test value;
*                          remaindercount: the number of its ‘range’ intDiv objects that yield a remainder when testing the divisibility of the test value
*                          testCount:  the maximum number of prior test values that were evenly divisible by any intDiv object.
*                          primecount starts at 2 since 0,1 and 2 cannot be counted as prime numbers
*                          if intDiv object is inactive it will return -1 if it is permanently  inactive then it will return -2
* 
*Class Invariant:  Client is given the function switchstate to have on and off state of the functionality of test()
*                          test() doesn't return anything you get your results from the get statements
*                          divisibleCount will increase depending on how many numbers had no remainder everytime you call test()
*                          remainderCount will increase based on how many numbers have remainders everytime you call test()
*
*/

#include "rangeDiv.h"
#include "intDiv.h"
#include <utility>
rangeDiv::rangeDiv(int input)
{
    if (input <= 0)
        input = 1;
    active = true;
    arr = new intDiv[input];
    divisibleCount = 0;
    remainderCount = 0;
    testCount = 0;
    range = input;
    primecount = 2;
    for (int i = 0; i < range; i++)
    {
        arr[i] = intDiv(PrimeNumGen());
    }
}

int rangeDiv::getdivisibleCount()
{
    return divisibleCount;
}

int rangeDiv::getremainderCount()
{
    return remainderCount;
}

int rangeDiv::gettestCount()
{
    return testCount;
}

void rangeDiv::switchstate()
{
    active = !active;
}

void rangeDiv::test(int num)
{
    if (num <= 0)
        num = 1;
    divisibleCount = 0;
    remainderCount = 0;
    if (!active)
        return;
    for (int i = 0; i < range; i++)
    {
        if (arr[i].test(num) == 0)
        {
            divisibleCount++;
            testCount++;
        }
        else
        {
            remainderCount++;
        }
    }
}

rangeDiv::~rangeDiv()
{
    delete[] arr;
}

unsigned int rangeDiv::PrimeNumGen()
{
    while (!isPrime(primecount))
    {
        primecount++;
    }
    int temp = primecount;
    primecount++;
    return temp;
}

bool rangeDiv::isPrime(int num)
{

    if (num <= 1)
        return false;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}

rangeDiv::rangeDiv(const rangeDiv &obj)
{
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        arr[i] = obj.arr[i];
    }
}

rangeDiv &rangeDiv::operator=(const rangeDiv &obj)
{
    if (this == &obj)
    {
        return *this;
    }
    delete[] arr;
    range = obj.range;
    divisibleCount = obj.divisibleCount;
    testCount = obj.testCount;
    remainderCount = obj.remainderCount;
    primecount = obj.primecount;
    arr = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}

rangeDiv::rangeDiv(rangeDiv &&obj)
{
    std::swap(range, obj.range);
    std::swap(divisibleCount, obj.divisibleCount);
    std::swap(testCount, obj.testCount);
    std::swap(remainderCount, obj.remainderCount);
    std::swap(primecount, obj.primecount);
    std::swap(arr, obj.arr);
}

rangeDiv &rangeDiv::operator=(rangeDiv &&obj)
{
    std::swap(range, obj.range);
    std::swap(divisibleCount, obj.divisibleCount);
    std::swap(testCount, obj.testCount);
    std::swap(remainderCount, obj.remainderCount);
    std::swap(primecount, obj.primecount);
    std::swap(arr, obj.arr);
    return *this;
}
rangeDiv &rangeDiv::operator+=(rangeDiv &obj)//it appends LHS rangeDiv's array with RHS rangeDiv's array
{

}
rangeDiv &rangeDiv::operator+(int &obj)//it adds a int to the end of the array
{

}
rangeDiv &rangeDiv::operator-=(rangeDiv &obj)//gets the difference between both rangeDiv objects
{

}

rangeDiv &rangeDiv::operator>(rangeDiv &obj)//compares the range of both rangeDiv objects
{

}

rangeDiv &rangeDiv::operator<(rangeDiv &obj)//compares the range of both rangeDiv objects
{

}




//template <typename T>
//void swap(T &lhs, T &rhs)
//{
//    T &temp(lhs);
//    lhs = std::move(rhs);
//    rhs = std::move(temp);
//}


//DONE used <utility>