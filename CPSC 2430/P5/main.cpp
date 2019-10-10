#include "range.h"
#include "multiQ.h"
#include "Factor.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;
int RNG(int input);
void multiQTest();
void rangeTest();
void factorTest();

time_t t;
int main()
{
    time_t t;
    srand((unsigned) time(&t));
    multiQTest();
    rangeTest();
    factorTest();

    return(0);
}
//PRE:Nothing
//POST:multiQTest results
void multiQTest()
{
    cout << "--- Starting multiQTest ---" << endl;

    const int fnum = 10;
    const int cycles = 5;
    multiQ obj1;
    multiQ obj2;
    int rand1;
    int rand2;
    for(int i = 0; i < cycles; i++)
    {
        rand1 = RNG(fnum);
        rand2 = RNG(fnum);
        cout << "push1:" << rand1 << "push2:" << rand2 << endl;
        obj1.pushFactor(rand1);
        obj2.pushFactor(rand2);
    }
    cout << "equal? " << (obj1 == obj2) << endl;
    cout << "testing == " << endl;
    obj1 = obj2;
    cout << "==? " << (obj1 == obj2) << endl;
    cout << "!=? " << (obj1 != obj2) << endl;
    multiQ obj3;
    multiQ obj4;
    for(int i = 0; i < cycles; i++)
    {
        rand1 = RNG(fnum);
        rand2 = RNG(fnum);
        cout << "push1:" << rand1 << "push2:" << rand2 << endl;
        obj3.pushFactor(rand1);
        obj4.pushFactor(rand2);
    }
    cout << "equal? " << (obj3 == obj4) << endl;
    cout << "testing == " << endl;
    obj3 = obj4;
    cout << "==? " << (obj3 == obj4) << endl;
    cout << "!=? " << (obj3 != obj4) << endl;
    delete obj1;
    delete obj2;
}
//PRE:Nothing
//POST:rangeTest results
void rangeTest()
{
    const int fnum = 20;
    int rand1 = RNG(fnum);
    int rand2 = RNG(fnum);
    cout << "--- Starting rangeTest ---" << endl;
    cout << "rand1: " << rand1 << " rand2: " << rand2 << endl;
    range obj1(RNG(rand1),RNG(rand2));
    rand1 = RNG(fnum);
    rand2 = RNG(fnum);
    cout << "rand1: " << rand1 << " rand2: " << rand2 << endl;
    range obj2(RNG(rand1),RNG(rand2));
    cout << "==?:" << (obj1 == obj2) << endl;
    cout << "testing =" << endl;
    obj1 = obj2;
    cout << "==?:" << (obj1 == obj2) << endl;
    cout << "!=?:" << (obj1 != obj2) << endl;
}
//PRE:Nothing
//POST:factorTest results
void factorTest()
{
    cout << "--- Starting factorTest ---" << endl;
    const int fnum = 20;
    int factor1 = RNG(fnum);
    int factor2 = RNG(fnum);
    cout << "factor1:" << factor1 << "factor2:" << factor2 << endl;
    Factor obj1(RNG(fnum));
    Factor obj2(RNG(fnum));
    cout << "==?:" << (obj1 == obj2) << endl;
    cout << "testing =" << endl;
    obj1 = obj2;
    cout << "==?:" << (obj1 == obj2) << endl;
    cout << "!=?:" << (obj1 != obj2) << endl;
    cout << "testing + and - operators" << endl;
    cout <<  "obj1's factor: " << obj1.getFactor() << endl;
    int randomnum = RNG(fnum);
    cout << "increasing obj1 by:" << (randomnum) << endl;
    for (int i = 0; i < randomnum; i++)
    {
        obj1++;
    }
    cout <<  "obj1's factor: " << obj1.getFactor() << endl;
    randomnum = RNG(fnum);
    cout << "decreasing obj1 by:" << (randomnum) << endl;
    for (int i = 0; i < randomnum; i++)
    {
        obj1--;
    }
    cout <<  "obj1's factor: " << obj1.get#include "range.h"
#include "multiQ.h"
#include "Factor.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
    using namespace std;
    int RNG(int input);
    void multiQTest();
    void rangeTest();
    void factorTest();

    time_t t;
    int main()
    {
        time_t t;
        srand((unsigned) time(&t));
        multiQTest();
        rangeTest();
        factorTest();

        return(0);
    }
//PRE:Nothing
//POST:multiQTest results
    void multiQTest()
    {
        cout << "--- Starting multiQTest ---" << endl;

        const int fnum = 10;
        const int cycles = 5;
        multiQ obj1;
        multiQ obj2;
        int rand1;
        int rand2;
        for(int i = 0; i < cycles; i++)
        {
            rand1 = RNG(fnum);
            rand2 = RNG(fnum);
            cout << "push1:" << rand1 << "push2:" << rand2 << endl;
            obj1.pushFactor(rand1);
            obj2.pushFactor(rand2);
        }
        cout << "equal? " << (obj1 == obj2) << endl;
        cout << "testing == " << endl;
        obj1 = obj2;
        cout << "==? " << (obj1 == obj2) << endl;
        cout << "!=? " << (obj1 != obj2) << endl;
        multiQ obj3;
        multiQ obj4;
        for(int i = 0; i < cycles; i++)
        {
            rand1 = RNG(fnum);
            rand2 = RNG(fnum);
            cout << "push1:" << rand1 << "push2:" << rand2 << endl;
            obj3.pushFactor(rand1);
            obj4.pushFactor(rand2);
        }
        cout << "equal? " << (obj3 == obj4) << endl;
        cout << "testing == " << endl;
        obj3 = obj4;
        cout << "==? " << (obj3 == obj4) << endl;
        cout << "!=? " << (obj3 != obj4) << endl;
        delete obj1;
        delete obj2;
    }
//PRE:Nothing
//POST:rangeTest results
    void rangeTest()
    {
        const int fnum = 20;
        int rand1 = RNG(fnum);
        int rand2 = RNG(fnum);
        cout << "--- Starting rangeTest ---" << endl;
        cout << "rand1: " << rand1 << " rand2: " << rand2 << endl;
        range obj1(RNG(rand1),RNG(rand2));
        rand1 = RNG(fnum);
        rand2 = RNG(fnum);
        cout << "rand1: " << rand1 << " rand2: " << rand2 << endl;
        range obj2(RNG(rand1),RNG(rand2));
        cout << "==?:" << (obj1 == obj2) << endl;
        cout << "testing =" << endl;
        obj1 = obj2;
        cout << "==?:" << (obj1 == obj2) << endl;
        cout << "!=?:" << (obj1 != obj2) << endl;
    }
//PRE:Nothing
//POST:factorTest results
    void factorTest()
    {
        cout << "--- Starting factorTest ---" << endl;
        const int fnum = 20;
        int factor1 = RNG(fnum);
        int factor2 = RNG(fnum);
        cout << "factor1:" << factor1 << "factor2:" << factor2 << endl;
        Factor obj1(RNG(fnum));
        Factor obj2(RNG(fnum));
        cout << "==?:" << (obj1 == obj2) << endl;
        cout << "testing =" << endl;
        obj1 = obj2;
        cout << "==?:" << (obj1 == obj2) << endl;
        cout << "!=?:" << (obj1 != obj2) << endl;
        cout << "testing + and - operators" << endl;
        cout <<  "obj1's factor: " << obj1.getFactor() << endl;
        int randomnum = RNG(fnum);
        cout << "increasing obj1 by:" << (randomnum) << endl;
        for (int i = 0; i < randomnum; i++)
        {
            obj1++;
        }
        cout <<  "obj1's factor: " << obj1.getFactor() << endl;
        randomnum = RNG(fnum);
        cout << "decreasing obj1 by:" << (randomnum) << endl;
        for (int i = 0; i < randomnum; i++)
        {
            obj1--;
        }
        cout <<  "obj1's factor: " << obj1.getFactor() << endl;

    }
    int RNG(int input)
    {
        return rand() % input + 1;
    }
    Factor() << endl;

}
int RNG(int input)
{
    return rand() % input + 1;
}
