/*
*Author:Shaun Lee
*Date:11/03/2019
*Version:v1.2
*Platform:VSCode
*
*Class Overview: this class inputs a number into a bunch of intDiv objects with incrementing distinct prime numbers and then counts how many have remainders, how many doesn't, and how many times you inputted a number
*
*Implementation invariant: 
*                           Prime number generator uses a seperate function to return a incrementing prime number example is 3,5,7,11
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
*                          move semantics swaps ownerships of both objects
*                           operator intDiv + intDiv will assign lhs an intdiv obj with the range of sum of both the ranges for example {2,3,5} + {2} = {2,3,5,7}
*                           + operators will return the sum of two intDiv objects
*                            += operator will assign LHS a new rangeDiv obj will the sum of both of  lhs and rhs ranges
*                           == operator will return true if lhs and rhs have the same data type or is the same obj
*                           != operator wil return the inverse of "=="
*                           all the subtraction operators like -=,- for both types. if range value is negative it will default to 1
*                           destructor is called when rangeDiv obj is getting deleted
*                           Supports mixed modes for rangeDivs and ints for addition and subtraction
*                           >,< compares the range numbers of both of the rangeDiv objects
*                           replaced move semantics with a swap method so it swaps ownership of the objects for both of the objects
*                           there are get methods for some data members such as diviscount and remaindercount that won't violate encapsulation
*                           change the code for switchstate
*                           change the code for the active condition in the test()
*                          
* 
*Class Invariant: 
                             Client is given the function switchstate to have on and off state of the functionality of test()
*                          test() doesn't return anything you get your results from the get statements
*                          divisibleCount will increase depending on how many numbers had no remainder everytime you call test()
*                          remainderCount will increase based on how many numbers have remainders everytime you call test()
*                          range is the size of the intDiv array
*                          The prime numbers aren't random they are incremental prime values 
*                           int can only go up to 2.3billion
*                           Prime count will start at 2 because prime numbers start at 2
*                           array is deleted when obj is deleted

*                            
*
*/
#include "rangeDiv.h"
#include "intDiv.h"

//Precondition:Any number except numbers that won't overflow a integer
//Postcondition: Instantiation of all fields and intDiv array, input number is the size of array
rangeDiv::rangeDiv(int input)
{
    active = true;
    if (input <= 0)
        input = 1;
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

//Precondition:none
//Postcondition:returns divisibleCount
int rangeDiv::getdivisibleCount()
{
    return divisibleCount;
}

//Precondition:none
//Postcondition: returns remainderCount
int rangeDiv::getremainderCount()
{
    return remainderCount;
}

//Precondition: none
//Postcondition: returns testCount
int rangeDiv::gettestCount()
{
    return testCount;
}

//Precondition:none
//Postcondition:changes the active state from positive to negative and negative to positive
void rangeDiv::switchstate()
{
    active = !active;
}
void rangeDiv::reset()
{
    active = true;
    divisibleCount = 0;
    remainderCount = 0;
    testCount = 0;
    primecount = 2;
}
//Precondition: Any number except numbers that won't overflow a integer
//Postcondition: testCount will incremented by 1, divisibleCount will increase depending on how many numbers had no remainder, remainderCount will increase based on how many numbers have remainders
void rangeDiv::test(int num)
{
    if (active)
    {
        if (num <= 0)
            num = 1;
        divisibleCount = 0;
        remainderCount = 0;
        for (int i = 0; i < range; i++)
        {
            int temp = arr[i].test(num);
            if (temp == 0)
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
}

rangeDiv::~rangeDiv()
{
    delete[] arr;
}

//Precondition: none
//Postcondition: generates a primenumber incrementing upwards 2,3,5,7,11
unsigned int rangeDiv::PrimeNumGen()
{
    while (!(primecount))
    {
        primecount++;
    }
    int temp = primecount;
    primecount++;
    return temp;
}

//Precondition: a int
//Postcondition: returns true or false depending if its prime
bool rangeDiv::isPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}

//Precondition: a existing rangeDiv obj
//Postcondition: copies to the intialized rangeDiv obj
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

//Precondition: a existing rangeDiv obj
//Postcondition: copies to the intialized rangeDiv obj
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

//Precondition:a rangeDiv object
//Postcondition:adds both of the ranges of the rangeDiv objects and then generates prime numbers up to the new range
//example: obj1 = [2,3,5] + obj2 = [2,3,5] -> obj1 = [2,3,5,7,11,13]
void rangeDiv::operator+=(rangeDiv rhs)
{
    primecount = 2;
    range += rhs.range;
    intDiv *temp = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] arr;
    arr = temp;
}

//Precondition: int
//Postcondition:similar to += rangediv rhs except you can add rangeDiv += intdiv
void rangeDiv::operator+=(int rhs)
{
    primecount = 2;
    range += rhs;
    intDiv *temp = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] arr;
    arr = temp;
}

//Precondition: int
//Postcondition:get the difference between both rangeDiv and int  for example {2,3,5} and 1 = {2,3}
void rangeDiv::operator-=(int rhs)
{
    primecount = 2;
    int newrange = range - rhs;
    if (newrange <= 0)
        newrange = 1;
    range = newrange;
    intDiv *temp = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] arr;
    arr = temp;
}

//Precondition:rangeDiv obj
//Postcondition:get the sum of both rangeDiv and rangeDiv  for example {2,3,5} and {2} = {2,3,5,7}
rangeDiv rangeDiv::operator+(rangeDiv rhs)
{
    rangeDiv originalobj(*this);
    originalobj.primecount = 2;
    originalobj.range += rhs.range;
    intDiv *temp = new intDiv[originalobj.range];
    for (int i = 0; i < originalobj.range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] originalobj.arr;
    originalobj.arr = temp;
    return originalobj;
}

//Precondition:int
//Postcondition:get the sum of both rangeDiv and int  for example {2,3,5} and 1 = {2,3,5,7}
rangeDiv rangeDiv::operator+(int rhs)
{
    rangeDiv originalobj(*this);
    originalobj.primecount = 2;
    originalobj.range += rhs;
    intDiv *temp = new intDiv[originalobj.range];
    for (int i = 0; i < originalobj.range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] originalobj.arr;
    originalobj.arr = temp;
    return originalobj;
}

//Precondition:int
//Postcondition:get the difference between both rangeDiv and int  for example {2,3,5} and 1 = {2,3}
rangeDiv rangeDiv::operator-(int rhs) 
{
    rangeDiv originalobj(*this);
    originalobj.primecount = 2;
    int newrange = range - rhs;
    if (newrange <= 0)
        newrange = 1;
    originalobj.range = newrange;
    intDiv *temp = new intDiv[originalobj.range];
    for (int i = 0; i < originalobj.range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] originalobj.arr;
    originalobj.arr = temp;
    return originalobj;
}

//Precondition:rangeDiv obj
//Postcondition:get the difference between both rangeDiv objs for example {2,3,5} and {2} = {2,3}
void rangeDiv::operator-=(rangeDiv rhs) 
{
    primecount = 2;
    int newrange = range - rhs.range;
    if (newrange <= 0)
        newrange = 1;
    range = newrange;
    intDiv *temp = new intDiv[range];
    for (int i = 0; i < range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] arr;
}

//Precondition:rangeDiv obj
//Postcondition:same as rangeDiv -= rangeDiv
rangeDiv rangeDiv::operator-(rangeDiv rhs)
{
    rangeDiv originalobj(*this);
    originalobj.primecount = 2;
    int newrange = originalobj.range - rhs.range;
    if (newrange <= 0)
        newrange = 1;
    originalobj.range = newrange;
    intDiv *temp = new intDiv[originalobj.range];
    for (int i = 0; i < originalobj.range; i++)
    {
        temp[i] = PrimeNumGen();
    }
    delete[] originalobj.arr;
    originalobj.arr = temp;
    return originalobj;
}

//Precondition:rangediv obj
//Postcondition:you can get the result of this boolean operator rangeDiv > rangeDiv
bool rangeDiv::operator>(rangeDiv rhs) //compares the range of both rangeDiv objects
{
    return (range > rhs.range);
}

//Precondition:rangediv obj
//Postcondition:same thing as previous but reverse
bool rangeDiv::operator<(rangeDiv rhs) //compares the range of both rangeDiv objects
{
    return (range < rhs.range);
}

//Precondition:rangeDiv obj
//Postcondition:checks to see if both rangeDiv obj have the same data values
bool rangeDiv::operator==(rangeDiv rhs)
{
    if (this == &rhs)
        return true;
    if (range != rhs.range)
        return false;
    bool same = true;
    for (int i = 0; i < range; i++)
    {
        if (arr[i] != rhs.arr[i])
            same = false;
    }
    return same;
}

//Precondition:rangeDiv obj
//Postcondition:same thing as previous but inverse
bool rangeDiv::operator!=(rangeDiv rhs)
{
    return !(*this == rhs);
}

//Precondition: a existing rangeDiv obj
//Postcondition: switch ownership of the obj
rangeDiv::rangeDiv(rangeDiv &&obj)
{
    swap(range, obj.range);
    swap(divisibleCount, obj.divisibleCount);
    swap(testCount, obj.testCount);
    swap(remainderCount, obj.remainderCount);
    swap(primecount, obj.primecount);
    swap(arr, obj.arr);
}

//Precondition: a existing rangeDiv obj
//Postcondition: switch ownership of the obj
rangeDiv &rangeDiv::operator=(rangeDiv &&obj)
{
    swap(range, obj.range);
    swap(divisibleCount, obj.divisibleCount);
    swap(testCount, obj.testCount);
    swap(remainderCount, obj.remainderCount);
    swap(primecount, obj.primecount);
    swap(arr, obj.arr);
    return *this;
}

//Precondition: 2 objects
//Postcondition:swaps ownership to both of the handlers
template <typename T>
void rangeDiv::swap(T &lhs, T &rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}
