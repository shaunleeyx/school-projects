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
 *                             the int in the operators can be negative
 *                             do not overflow the integer
 *                             there is mixed mode operators for intdiv and int
 *                              mixed mode operators consist of +=,-,+,-=
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
    intDiv operator+(intDiv rhs); 
    intDiv operator-(intDiv rhs); 
    void operator+=(intDiv rhs);  
    void operator+=(int rhs);     
    intDiv operator-(int rhs);    
    intDiv operator+(int rhs);    
    void operator-=(intDiv rhs);  
    intDiv operator-=(int rhs);  
    bool operator>(intDiv rhs);
    bool operator<(intDiv rhs);
    bool operator!=(intDiv rhs);
    bool operator==(intDiv rhs);
};

#endif
