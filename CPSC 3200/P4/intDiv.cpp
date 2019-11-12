/*
 *Author Shaun Lee
 *11/03/2019
 *Version 1.2
 *Platform:VSCode
 *
 *Class Overview: This class gets the remainder of two numbers with some rules explained in the invariances
 *
 *        Class Invariant:    active is true and perm is false when intialized by constructor.
 *                            active changes when test returns the same number twice.
 *                            perm changes to false when reset() is invoked when active is true
 *                            reset() resets the program to its default state even if its permanently deactivated
 *                            revive() resets the program to its default state if its inactive and is permanently deactivated when used while its active
 *                            num in constructor has to be from 0 to 2147483648 
 *                            num passed in test has to be from -2147483648 to 2147483648
 *                            num in test is unsigned
 *                            if intdivobject inactive then test() will return -1
 *                            if intdiv object is perminactive then test() will return -2 
 * 
 *            Implementation invariant:     renamed reset() to revive()
 *            (with assumptions)            removed getPerm()
 *                                          change the argument of the constructor to a uint
 *                                          renamed field perm to perminactive
 *                                          made a if statement in the revive function that if perminactive is active then it just returns
 *                                          reset() resets the program to its default state even if its permanently deactivated
 *                                          revive() resets the program to its default state if its inactive and is permanently deactivated when used while its active
 *                                          changed line 66 from active = true to active = !active;
 *                                          if inactive then test() will return -1
 *                                          if perminactive then test() will return -2
 */

#include "intDiv.h"

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

intDiv::intDiv()
{
    //don't have to do anything here since no allocated heap memory
}

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

bool intDiv::getActive()
{
    return active;
}

void intDiv::reset()
{
    perminactive = false;
    active = true;
    lastnum = -1;
}
//TODO
intDiv &intDiv::operator+(intDiv &obj)//adds intDivA's div with intDivB's div
{
    
}

//TODO
intDiv &intDiv::operator-(intDiv &obj)//minuses intDivA's div with intDivB's div
{
    
}

//TODO
intDiv &intDiv::operator+=(intDiv &obj)//same thing as line 105 but with += 
{
    
}

//TODO
intDiv &intDiv::operator+=(int &obj)//adds intDiv's div by int
{
    
}

//TODO
intDiv &intDiv::operator-=(intDiv &obj)//same thing as line 105 but with += 
{
    
}

//TODO
intDiv &intDiv::operator-=(int &obj)//subracts intDiv's div by int

{
    
}