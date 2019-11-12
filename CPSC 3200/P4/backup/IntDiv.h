#ifndef INTDIV_H
#define INTDIV_H

/**
 *Class Overview: This class gets the remainder of two numbers with some rules explained in the invariances
 *Class Invariant:active is true and perm is false when intialized by constructor.active changes when test returns the same number twice. perm changes to false when reset() is invoked when active is true
 *Interface Invariant:div number is positive. negative div and 0 numbers default to 1 so no divide by 0. When active is false it disables the functionality of test(). This can be fixed by reset(). However if perm is active it is permanently disabled
 **/

 class intDiv
 {
private:
    unsigned int div;
    bool active = false;
    bool perminactive = false;
    int lastnum = 0;

    //PRECONDITION:input any number
    //POSTCONDITION: it sets div to num and intializes all other fields to a value or a state
public:
    intDiv(unsigned int num);
    //PRECONDITION:input a positive number
    //POSTCONDITION:returns the remainder of the number you inputted divided by div or -1 or -2 depending on the state of active and perm
    int test(unsigned int num);
    //PRECONDITION:active can be true or false
    //POSTCONDITION: if active is false then it is reinitialized to true and if active is true then permanent is true
    void revive();
    //PRECONDITION:none
    //POSTCONDITION:returns active's state
    bool getActive();

    void reset();

 };



/**Implementation invariant: renamed reset() to revive()
 *                           removed getPerm()
 *                           change the argument of the constructor to a uint
 *                           renamed field perm to perminactive
 *                           made a if statement in the revive function that if perminactive is active then it just returns
**/

#endif