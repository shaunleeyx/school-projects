/**
 *Author:Shaun Lee
 *Date:11/11/2019
 *Version:v1.0
 *Platform:VSCode
 **/
/**Class Overview: Driver Tests out the operator overload features for P4
 * 
 * ASSUMPTIONS:It is up to the client to get the ideal test results they want
 * run it as many times as possible to get the results you want if you see unstable results it could be because of the active on each rangeDiv or intDiv object
 * If the results may look like -2 or -1 or 0 it could be the object's active state being false.
 * I have 2 functions that tests out each class individually through a set of testing functions for each individual operator
 * it prints out the non encapsulated values
**/
#include <queue>
#include <iostream>
#include <ctime>
#include "intDiv.h"
#include "rangeDiv.h"
#include <memory>
using namespace std;
void printStats(rangeDiv rd);
//IntDiv operators

//Precondition:intDiv,intDiv,int
//Postcondition: prints out the test for returns intDiv obj with sum of both lhs and rhs 
void IntDivPlusIntDiv(intDiv id1, intDiv id2, int num)
{
    cout << "testing intDiv + intDiv" << endl;
    cout << "(id1 + id2).test(num):" << (id1 + id2).test(num) <<endl << endl;
}

//Precondition:intDiv,intDiv,int
//Postcondition:prints out the test for returns intDiv obj with difference between both lhs and rhs
void IntDivMinusIntDiv(intDiv id1, intDiv id2, int num)
{
    cout << "testing intDiv - intDiv" << endl;
    cout << "(id1 + id2).test(num):" << (id1 + id2).test(num) <<endl << endl;
}

//Precondition:intDiv,intDiv,int
//Postcondition:prints out the test for assigns lhs to the sum of both lhs and rhs divs
void IntDivPlusEqualsIntDiv(intDiv id1, intDiv id2, int num)
{
    cout << "testing intDiv += intDiv" << endl;
    id1 += id2;
    cout << "id1 += id2; id1.test(num):" << id1.test(num) <<endl << endl;
}

//Precondition:intDiv,int,int
//Postcondition:prints out the test for assigns lhs  to the sum of lhs's div and rhs int 
void IntDivPlusEqualsInt(intDiv id, int i, int num)
{
    cout << "testing intDiv += int" << endl;
    id += i;
    cout << "id += i;  id.test(num):" << id.test(num) <<endl << endl;
}

//Precondition:intDiv,int,int
//Postcondition:prints out the test for returns a intdiv obj with the difference between intDiv's div and int
void IntDivMinusInt(intDiv id, int i, int num)
{
    cout << "testing IntDiv - Int" << endl;
    cout << "(id - i).test(num):" << (id - i).test(num) <<endl << endl;
}

//Precondition:intDiv,int,int
//Postcondition:prints out the test for returns an intdiv object with the sum of both the intDiv's div and the int
void IntDivPlusInt(intDiv id, int i, int num)
{
    cout << "testing intDiv + int" << endl;
    cout << "(id + i).test(num):" << (id + i).test(num) <<endl << endl;
}

//Precondition:intDiv,intDiv,int
//Postcondition:prints out the test for assigns lhs intDiv obj with the difference between both lhs and rhs's div values
void IntDivMinusEqualsIntDiv(intDiv id1, intDiv id2, int num)
{
    cout << "testing intDiv -= intDiv" << endl;
    id1 -= id2;
    cout << "id1 -= id2; id1.test(num):" << id1.test(num) <<endl << endl;
}

//Precondition:intDiv,int,int
//Postcondition:prints out the test for assigns lhs intDiv obj with the difference between intDiv's div and rhs int
void IntDivMinusEqualsInt(intDiv id, int i, int num)
{
    cout << "testing intDiv -= int" << endl;
    id -= i;
    cout << "id -= i;  id.test(num):" << id.test(num) <<endl << endl;
}

//Precondition:intDiv,intDiv
//Postcondition:prints out if intDiv1 obj's div is greater than intDiv2 obj's div
void IntDivGreaterIntDiv(intDiv id1, intDiv id2)
{
    cout << "testing intDiv > intDiv" << endl;
    cout << "id1 > id2:" << (id1 > id2) <<endl << endl;
}

//Precondition:intDiv,intDiv
//Postcondition:prints out if intDiv1 obj is less than intDiv2 obj
void IntDivLessIntDiv(intDiv id1, intDiv id2)
{
    cout << "testing intDiv < intDiv" << endl;
    cout << "(id1 < id2):" << (id1 < id2) <<endl << endl;
}

//Precondition:intdiv obj, intdiv obj
//Postcondition:checks to see if intdiv1 obj is not the same as intdiv 2 obj
void IntDivNotEqualsIntDiv(intDiv id1, intDiv id2)
{
    cout << "testing intDiv != intDiv" << endl;
    cout << "(id1 != id2):" << (id1 != id2) <<endl << endl;
}

//Precondition:intdiv obj,intdiv obj
//Postcondition:prints out if intdiv1 obj is equal to intdiv2 obj
void IntDivEqualsIntDiv(intDiv id1, intDiv id2)
{
    cout << "testing intDiv == intDiv" << endl;
    cout << "(id1 == id2):" << (id1 == id2) <<endl << endl;
}

//rangeDiv operators

//Precondition:rangediv,rangediv,int
//Postcondition:prints out the data members of rangediv obj1 after the += operator with rangeDiv2 obj
void RangeDivPlusEqualsRangeDiv(rangeDiv rd1, rangeDiv rd2, int num)
{
    cout << "testing RangeDiv += RangeDiv" << endl;
    rd1 += rd2;
    rd1.test(num);
    cout << "rd1 += rd2;" <<endl << endl;
    printStats(rd1);
}

//Precondition:rangeDiv,rangeDiv,int
//Postcondition:prints out the data members of lhs after rangeDiv obj1 + rangeDiv obj 2
void RangeDivPlusRangeDiv(rangeDiv rd1, rangeDiv rd2, int num)
{
    cout << "testing RangeDiv + RangeDiv" << endl;
    rangeDiv temp = (rd1 + rd2);
    temp.test(num);
    cout << "rd1 + rd2" <<endl << endl;
    printStats(temp);
}

//Precondition:rangeDiv obj,int,int
//Postcondition:prints out the data members of lhs after rangeDiv obj + int
void RangeDivPlusInt(rangeDiv rd, int i, int num)
{
    cout << "testing RangeDiv + Int" << endl;
    rangeDiv temp = (rd + i);
    temp.test(num);
    cout << "rd + i" <<endl << endl;
    printStats(temp);
}

//Precondition: RangeDiv, int,int
//Postcondition:prints out the data members of lhs after  rangeDiv - int
void RangeDivMinusInt(rangeDiv rd, int i, int num)
{
    cout << "testing RangeDiv - Int" << endl;
    rangeDiv temp = (rd - i);
    temp.test(num);
    cout << "rd - i" <<endl << endl;
    printStats(temp);
}

//Precondition: rangeDiv,int,int 
//Postcondition:prints out the data members of lhs after rangeDiv += int 
void RangeDivPlusEqualsInt(rangeDiv rd, int i, int num)
{
    cout << "testing RangeDiv += Int" << endl;
    rd += i;
    rd.test(num);
    cout << "rd += i" <<endl << endl;
    printStats(rd);
}

//Precondition:rangeDiv,int,int
//Postcondition:prints out the data members of lhs after rangeDiv -= int 
void RangeDivMinusEqualsInt(rangeDiv rd, int i, int num)
{
    cout << "testing RangeDiv -= Int" << endl;
    rd -= i;
    rd.test(num);
    cout << "rd -= i" <<endl << endl;
    printStats(rd);
}

//Precondition:rangeDiv,rangeDiv,int
//Postcondition:prints out the data members of lhs after rangeDiv1 -= rangeDiv2
void RangeDivMinusEqualsRangeDiv(rangeDiv rd1, rangeDiv rd2, int num)
{
    cout << "testing RangeDiv -= RangeDiv" << endl;
    rd1 -= rd2;
    rd1.test(num);
    cout << "rd1 -= rd2" <<endl << endl;
    printStats(rd1);
}

//Precondition:rangeDiv,rangeDiv,int
//Postcondition:prints out the data members of rhs after rangeDiv1 - rangeDiv2 
void RangeDivMinusRangeDiv(rangeDiv rd1, rangeDiv rd2, int num)
{
    cout << "testing RangeDiv - RangeDiv" << endl;
    rangeDiv temp = (rd1 - rd2);
    temp.test(num);
    cout << "rd1 - rd2" <<endl << endl;
    printStats(temp);
}

//Precondition:rangeDiv,rangeDiv
//Postcondition:prints out the results of rangeDiv1 < rangeDiv2
void RangeDivLessRangeDiv(rangeDiv rd1, rangeDiv rd2)
{
    cout << "testing RangeDiv < RangeDiv" << endl;
    cout << "rd1 < rd2 :" << (rd1 < rd2) <<endl << endl;
}

//Precondition:rangeDiv,rangeDiv
//Postcondition:prints out the result of rangeDiv1 > rangeDiv2
void RangeDivGreaterRangeDiv(rangeDiv rd1, rangeDiv rd2)
{
    cout << "testing RangeDiv > RangeDiv" << endl;
    cout << "rd1 > rd2:" << (rd1 > rd2) <<endl << endl;
}

//Precondition:rangediv,rangediv
//Postcondition:prints out the result of rangediv1 == rangediv2
void RangeDivEqualsRangeDiv(rangeDiv rd1, rangeDiv rd2)
{
    cout << "testing RangeDiv == RangeDiv" << endl;
    cout << "rd1 == rd2:" << (rd1 == rd2) <<endl << endl;
}

//Precondition:rangeDiv,rangeDiv
//Postcondition:prints out the result of rangeDiv1 != rangeDiv2
void RangeDivNotEqualsRangeDiv(rangeDiv rd1, rangeDiv rd2)
{
    cout << "testing RangeDiv != RangeDiv" << endl;
    cout << "rd1 != rd2:" << (rd1 == rd2) <<endl << endl;
}

//Precondition:rangeDiv
//Postcondition:prints out the divisibleCount,remainderCount,testCount of rangeDiv obj 
void printStats(rangeDiv rd)
{
    cout << "divisibleCount:" << rd.getdivisibleCount() << "\tremainderCount:" << rd.getremainderCount() << "\ttestCount:" << rd.gettestCount() << endl;
}

//Precondition:int,int 
//Postcondition:returns a random integer from the first int to the second int
int rng(int min, int max)
{
    return rand() % max + min;
}

//Precondition:none
//Postcondition:runs the intDiv test cases
void intDivTest()
{
    cout << "---- intDivTest() ----" << endl;
    const int divMAX = 100;
    const int divMIN = 1;
    const int iMIN = 1;
    const int iMAX = 10;
    const int tMIN = 1 ;
    const int tMAX = 200;
    int div1 = rng(divMIN,divMAX);
    int div2 = rng(divMIN,divMAX);
    intDiv id1(div1);
    intDiv id2(div2);
    int testarg = rng(tMIN,tMAX);
    int i = rng(iMIN,iMAX);
    cout << "div for id1 & id is " << div1 << "\tdiv for id2 is " << div2 <<"\t i is " << i << endl << endl;
    IntDivPlusIntDiv(id1,id2,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivMinusIntDiv(id1,id2,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivPlusEqualsIntDiv(id1,id2,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivPlusEqualsInt(id1,i,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivMinusInt(id1,i,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivPlusInt(id1,i,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivMinusEqualsIntDiv(id1,id2,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivMinusEqualsInt(id1,i,testarg);
    testarg = rng(tMIN,tMAX);
    cout << "num:" << testarg << endl;
    IntDivGreaterIntDiv(id1,id2);
    IntDivLessIntDiv(id1,id2);
    IntDivNotEqualsIntDiv(id1,id2);
    IntDivEqualsIntDiv(id1,id2);
     
}

//Precondition:None
//Postcondition:runs rangeDiv test cases
void rangeDivTest()
{
    cout << "---- rangeDivTest() ----" << endl;
    const int rdMAX = 10;
    const int rdMIN = 1; 
    const int tMIN = 1 ;
    const int tMAX = 200;
    const int iMIN = 1;
    const int iMAX = 10;
    int range1 = rng(rdMIN, rdMAX);
    int range2 = rng(rdMIN, rdMAX);
    int num = rng(tMIN,tMAX);
    int i = rng(iMIN,iMAX);
    cout << "range number for rd1 & rd:" << range1 << "\trange number for rd2:" << range2 <<  endl <<endl;
    rangeDiv rd1(range1);
    rangeDiv rd2(range2);
    RangeDivPlusEqualsRangeDiv(rd1,rd2,num);
    RangeDivPlusRangeDiv(rd1,rd2,num);
    RangeDivPlusInt(rd1,i,num);
    RangeDivMinusInt(rd1,i,num);
    RangeDivPlusEqualsInt(rd1,i,num);
    RangeDivMinusEqualsInt(rd1,i,num);
    RangeDivMinusEqualsRangeDiv(rd1,rd2,num);
    RangeDivMinusRangeDiv(rd1,rd2,num);
    RangeDivLessRangeDiv(rd1,rd2);
    RangeDivGreaterRangeDiv(rd1,rd2);
    RangeDivEqualsRangeDiv(rd1,rd2);
    RangeDivNotEqualsRangeDiv(rd1,rd2) ;
}

int main()
{
   
}