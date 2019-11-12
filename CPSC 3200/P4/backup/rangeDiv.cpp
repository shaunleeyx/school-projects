//
// Created by Shaun Lee on 2019-10-13.
//

#include "rangeDiv.h"
#include "IntDiv.h"


rangeDiv::rangeDiv(int num){
    arr = new intDiv[num];
    range = num;
    primecount = 2;
    for(int i = 0; i < num; i++){
        arr[i] = new intDiv(PrimeNumGen());
    }
}

rangeDiv::~rangeDiv(){
    delete[] arr;
}


unsigned int rangeDiv::PrimeNumGen() {
    while(!isPrime(primecount)){
        primecount++;
    }
    int temp = primecount;
    primecount++;
    return temp;
}

bool rangeDiv::isPrime(int num) {

    if (num <= 1)
        return false;

    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;

    return true;
}
