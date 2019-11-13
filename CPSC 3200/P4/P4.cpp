/**
 *Author:Shaun Lee
 *Date:11/11/2019
 *Version:v1.0
 *Platform:VSCode
 **/
//Class Overview: Driver Tests out the operator overload features for P4
#include <queue>
#include <iostream>
#include <ctime>
#include "intDiv.h"
#include "rangeDiv.h"
#include <memory>
using namespace std;

int main()
{
    rangeDiv a(7);
    rangeDiv b(9);
    rangeDiv c(5);
    cout << (a < b) << endl;
    return 0;
}
