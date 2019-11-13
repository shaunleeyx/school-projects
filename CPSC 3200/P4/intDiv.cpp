/*
 *Author Shaun Lee
 *11/03/2019
 *Version 1.2
 *Platform:VSCode
 *
 *Class Overview: This class gets the remainder of two numbers with some rules explained in the invariances
 *
 *       Class Invariant:    active is true and perm is false when intialized by constructor.
 *                                   active changes when test returns the same number twice.
 *                                   perm changes to false when reset() is invoked when active is true
 *                                   reset() resets the program to its default state even if its permanently deactivated
 *                                   revive() resets the program to its default state if its inactive and is permanently deactivated when used while its active
 *                                   num in constructor has to be from 0 to 2147483648 
 *                                   num passed in test has to be from -2147483648 to 2147483648
 *                                   num in test is unsigned
 *                                   if intdivobject inactive then test() will return -1
 *                                   if intdiv object is perminactive then test() will return -2 
 * 
 *            Implementation invariant:     renamed reset() to revive()
 *            (with assumptions)                removed getPerm()
 *                                                         change the argument of the constructor to a uint
 *                                                         renamed field perm to perminactive
 *                                                         made a if statement in the revive function that if perminactive is active then it just returns
 *                                                         reset() resets the program to its default state even if its permanently deactivated
 *                                                         revive() resets the program to its default state if its inactive and is permanently deactivated when used while its active
 *                                                        changed line 66 from active = true to active = !active;
 *                                                        if inactive then test() will return -1
 *                                                        if perminactive then test() will return -2
 */

#include "intDiv.h"

//Precondition:input any number
//Postcondition: it sets div to num and intializes all other fields to a value or a state
intDiv::intDiv(unsigned int num)
{
    if (num <= 0)
        num = 1;
    div = num;
    active = true;
    perminactive = false;
    lastnum = -1;
    testcount = 0;
}

//Precondition:input a positive number
//Postcondition:returns the remainder of the number you inputted divided by div or -1 or -2 depending on the state of active and perm
int intDiv::test(unsigned int num)
{
    int remainder = num % div;
    if (remainder == 0)
    {
        testcount++;
    }
    if (lastnum == (int)(remainder))
    {
        active = false;
    }
    if (perminactive)
    {
        return -2;
    }
    if (active)
    {
        lastnum = static_cast<int>(remainder);
        return static_cast<int>(lastnum);
    }
    else
    {
        return -1;
    }
}

//Precondition:active can be true or false
//Postcondition: if active is false then it is reinitialized to true and if active is true then permanent is true
void intDiv::revive()
{
    if (perminactive)
    {
        return;
    }
    if (active)
    {
        perminactive = true;
    }
    else
    {
        active = !active;
        lastnum = -1;
    }
}

//Precondition:none
//Postcondition:returns active's state
bool intDiv::getActive()
{
    return active;
}

//Precondition:none
//Postcondition: resets object to default state (including perminactive)
void intDiv::reset()
{
perminactive = false;
active = true;
lastnum = -1;
}

//Precondition:
//Postcondition:
intDiv intDiv::operator+(intDiv rhs) //adds intDivA's div with intDivB's div
{
    intDiv originalobj(*this);
    originalobj.div += rhs.div;
    return originalobj; 
}

//Precondition:
//Postcondition:
intDiv intDiv::operator-(intDiv rhs) //minuses intDivA's div with intDivB's 
{ 
    intDiv originalobj(*this);
    originalobj.div -= rhs.div;
    return originalobj; 
}

//Precondition:
//Postcondition:
void intDiv::operator+=(intDiv rhs) //same thing as line 105 but with +=;
{ 
    div += rhs.div;
}

//Precondition:
//Postcondition:
void intDiv::operator-=(intDiv rhs) //same thing as line 105 but with +=
{
    div -= rhs.div;
}

//Precondition:
//Postcondition:
void intDiv::operator+=(int rhs) //adds intDiv's div by int
{
    div += rhs;
}

//Precondition:
//Postcondition:
intDiv intDiv::operator-=(int rhs) //subracts intDiv's div by int
{ 
     intDiv originalobj(*this);
    originalobj.div -= rhs;
    return originalobj; 
}

//Precondition:
//Postcondition:
intDiv intDiv::operator-(int rhs) //minuses intDivA's div with intDivB's
{
    intDiv originalobj(*this);
    originalobj.div -= rhs;
    return originalobj;
}

//Precondition:
//Postcondition:
intDiv intDiv::operator+(int rhs) //minuses intDivA's div with intDivB's
{
    intDiv originalobj(*this);
    originalobj.div += rhs;
    return originalobj;
}

//Precondition:
//Postcondition:
bool intDiv:: operator>(intDiv rhs)
{ 
     return (div > rhs.div);
}

//Precondition:
//Postcondition:
bool intDiv:: operator<(intDiv rhs)
{
    return (div < rhs.div);
}

int intDiv::getDiv(){
    return div;
}