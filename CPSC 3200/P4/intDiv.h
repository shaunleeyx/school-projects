#ifndef INTDIV_H
#define INTDIV_H

/*Author Shaun Lee
 *11/03/2019
 *Version 1.2
 *Platform:VSCode
 *Interface Invariant:         div number is positive.
 *                             negative div and 0 numbers default to 1 so no divide by 0.
 *                             When active is false it disables the functionality of test().
 *                             This can be fixed by reset(). However if perm is active it is permanently disabled
 *                             Did not implement a '=' operator since it interferes with the intialization of a intDiv array in the rangeDiv class
 * 
 **/

class intDiv
{
private:
    unsigned int div;
    bool active;
    bool perminactive;
    int lastnum;
    int testcount;

    //PRECONDITION:input any number
    //POSTCONDITION: it sets div to num and intializes all other fields to a value or a state
public:
    intDiv();
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
    //PRECONDITION:none
    //POSTCONDITION: resets object to default state (including perminactive)
    void reset();
    //PRECONDITION: a existing rangeDiv obj
    //POSTCONDITION: switch ownership of the obj
    intDiv &operator + (intDiv &obj); //IntDiv a = IntDiv b + Intdiv c
    intDiv &operator - (intDiv &obj);//IntDiva = IntDiv b - IntDiv b
    intDiv &operator += (intDiv &obj);//IntDiv a += intDiv b
    intDiv &operator += (int &obj);//IntDiv a += int b
    intDiv &operator -= (intDiv &obj);//intDiv a -= intdiv b
    intDiv &operator -= (int &obj);//intDiv a -= int b
    intDiv &operator > (intDiv &obj);
    
};

#endif
