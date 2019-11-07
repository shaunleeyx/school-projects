//
// Created by Shaun Lee on 2019-10-13.
//
#include  "IntDiv.h"
#ifndef CLIONPROJECTS_RANGEDIV_H
#define CLIONPROJECTS_RANGEDIV_H


class rangeDiv {
public:
    rangeDiv(int num);
    ~rangeDiv();

private:
    int range;
    int primecount;
    bool static isPrime(int num);
    unsigned int PrimeNumGen();
    intDiv* arr;
};


#endif //CLIONPROJECTS_RANGEDIV_H
