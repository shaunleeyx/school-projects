/**
 *Author:Shaun Lee
 *Date:11/03/2019
 *Version:v1.2
 *Platform:Clion C++11
 **/
//Class Overview: Driver Tests lsout move semantics,unique pointers, shared pointers, and rangeDiv functionality
#include <queue>
#include <iostream>
#include <ctime>
#include  "intDiv.h"
#include "rangeDiv.h"
#include <memory>
using namespace std;

int RNG();
void testuniquePtr();
void testsharedPtr();
void testrangeDiv();
void testMoveSemantics();
void test(rangeDiv *obj);

const int SIZE = 5;
int main() {
    srand(time(0));
    testuniquePtr();
    testsharedPtr();
    testMoveSemantics();
    testrangeDiv();
}
//tests out the move semantics with smart pointers and queue
void testMoveSemantics(){
    cout << "\n--testing move semantics with queue --" << endl;
    queue<unique_ptr<rangeDiv>> uniqueQueue;
    unique_ptr<rangeDiv> uniquePtr(new rangeDiv(RNG()));
    uniqueQueue.push(move(uniquePtr));
    cout << "\ninserted uniqueptr in to queue" << endl;
    cout << "uniquePtr null:" << (uniquePtr == nullptr) << endl;
    uniqueQueue.pop();
    cout << "popped object out of queue" << endl;
}
// tests out rangeDiv functionality
void testrangeDiv(){
    cout << "\n--testing testrangeDiv()--" << endl;
    int arrSize = 10;
    cout << "array size:" << arrSize << endl;
    cout << "\n-uniquePtr1-\n" << endl;
    unique_ptr<rangeDiv> uniquePtr1(new rangeDiv(arrSize));
    test(uniquePtr1.release());
    cout << "\n-uniquePtr2-\n" << endl;
    unique_ptr<rangeDiv> uniquePtr2(new rangeDiv(arrSize));
    test(uniquePtr2.release());
    cout << "\n-uniquePtr3-\n" << endl;
    unique_ptr<rangeDiv> uniquePtr3(new rangeDiv(arrSize));
    test(uniquePtr3.release());
    cout << "\n-uniquePtr4-\n" << endl;
    unique_ptr<rangeDiv> uniquePtr4(new rangeDiv(arrSize));
    test(uniquePtr4.release());
    cout << "\n-uniquePtr5-\n" << endl;
    unique_ptr<rangeDiv> uniquePtr5(new rangeDiv(arrSize));
    test(uniquePtr5.release());
    rangeDiv a(RNG());
    cout << "\n--testing copying--\n" << endl;
    a.test(RNG());
    cout << "a:" << endl;
    cout << "divisible count:" << a.getdivisibleCount() << "\tremainderCount:" << a.getremainderCount() << "\ttestCount:" << a.gettestCount() << endl;
    rangeDiv b(a);
    cout << "rangeDiv b(a); b:" << endl;
    cout << "divisible count:" << b.getdivisibleCount() << "\tremainderCount:" << b.getremainderCount() << "\ttestCount:" << b.gettestCount() << endl;
    rangeDiv c(RNG());
    c = a;
    cout << "c = a; c:" << endl;
    cout << "divisible count:" << c.getdivisibleCount() << "\tremainderCount:" << c.getremainderCount() << "\ttestCount:" << c.gettestCount() << endl;
    rangeDiv *ptrA = new rangeDiv(RNG());
    ptrA->test(RNG());
    cout << "ptrA:" << endl;
    cout << "divisible count:" << ptrA->getdivisibleCount() << "\tremainderCount:" << ptrA->getremainderCount() << "\ttestCount:" << ptrA->gettestCount() << endl;
    rangeDiv *ptrB;
    ptrB = ptrA;
    cout << "ptrB = ptrA; ptrB:" << endl;
    cout << "divisible count:" << ptrB->getdivisibleCount() << "\tremainderCount:" << ptrB->getremainderCount() << "\ttestCount:" << ptrB->gettestCount() << endl;





}

//helper function for testrangeDiv()
void test(rangeDiv *obj){
    int testNum;

    for(int i = 0; i < SIZE; i++)
    {
        testNum = RNG();
        cout <<  "count:" << i+1 <<  "\ttestnum:" << testNum << endl;
        obj->test(testNum);
        cout << "divisible count:" << obj->getdivisibleCount() << "\tremainderCount:" << obj->getremainderCount() << "\ttestCount:" << obj->gettestCount() << endl;
    }
    obj->switchstate();
    cout << "--state switched--" << endl;
    testNum = RNG();
    cout << "testnum:" << testNum << endl;
    obj->test(testNum);
    cout << "divisible count:" << obj->getdivisibleCount() << "\tremainderCount:" << obj->getremainderCount() << "\ttestCount:" << obj->gettestCount() << endl;
    obj->switchstate();
    cout << "--state switched--" << endl;
    testNum = RNG();
    cout << "testnum:" << testNum << endl;
    obj->test(testNum);
    cout << "divisible count:" << obj->getdivisibleCount() << "\tremainderCount:" << obj->getremainderCount() << "\ttestCount:" << obj->gettestCount() << endl;

}
//tests out unique pointers
void testuniquePtr(){
    cout << "\n--testing unique pointer's feature--" << endl;
    unique_ptr<rangeDiv> uniquePtr1(new rangeDiv(RNG()));
    cout << "uniquePtr1 == null: " << (uniquePtr1 == nullptr) << endl;
    unique_ptr<rangeDiv> uniquePtr2 = move(uniquePtr1);
    cout << "uniquePtr2 is referencing uniquePtr1's object" << endl;
    cout << "uniquePtr1 == null: " << (uniquePtr1 == nullptr) << endl;
    cout << "uniquePtr2 == null: " << (uniquePtr2 == nullptr) << endl;

}
//tests out shared pointer's features
void testsharedPtr(){
    cout << "\n--testing shared pointer's feature--" << endl;
    shared_ptr<rangeDiv> sharedPtr1 = make_shared<rangeDiv>(RNG());
    cout << "references to sharedPtr1's object  reference count: " << sharedPtr1.use_count() << endl;
    shared_ptr<rangeDiv> sharedPtr2 = sharedPtr1;
    cout << "referencing sharedPtr2 to sharedPtr's object" << endl;
    cout << "references to sharedPtr1's object  reference count:" << sharedPtr1.use_count() << endl;
    shared_ptr<rangeDiv> sharedPtr3 = sharedPtr2;
    cout << "referencing sharedPtr3 to sharedPtr2's object" << endl;
    cout << "references to sharedPtr1's object  reference count:" << sharedPtr1.use_count() << endl;
    cout << "references to sharedPtr3's object  reference count:" << sharedPtr3.use_count() << endl;
}
// random number generator from 1 to 100
int RNG(){
    return (rand()%100)+1;
}





