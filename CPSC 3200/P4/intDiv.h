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
    
public:
    intDiv(unsigned int num = 1);
    int test(unsigned int num);
    void revive();
    bool getActive();
    void reset();
    intDiv operator + (intDiv rhs); //IntDiv a = IntDiv b + Intdiv c
    intDiv operator - (intDiv rhs);//IntDiva = IntDiv b - IntDiv b
    void operator += (intDiv rhs);//IntDiv a += intDiv b
    void operator += (int rhs);//IntDiv a += int b
    intDiv operator-(int rhs); //minuses intDivA's div with intDivB's
    intDiv operator+(int rhs); //minuses intDivA's div with intDivB's
    void operator -= (intDiv rhs);//intDiv a -= intdiv b
    intDiv operator -= (int rhs);//intDiv a -= int b
    bool operator > (intDiv rhs);
    bool operator < (intDiv rhs);
    int getDiv(); 
};

#endif
