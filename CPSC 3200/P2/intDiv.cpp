/*
 *Author Shaun Lee
 *11/03/2019
 *Version 1.2
 *Platform:Clion
 *
*/
#include "intDiv.h"


intDiv::intDiv(unsigned int num) {
    if (num <= 0) num = 1;
    div = num;
    active = true;
    perminactive = false;
    lastnum = -1;
}

intDiv::intDiv() {

}

int intDiv::test(unsigned int num) {
    if (lastnum == (int) (num % div)) {
        active = false;
    }
    if (perminactive) {
        return -2;
    }
    if (active) {
        lastnum = static_cast<int>(num % div);
        return static_cast<int>(lastnum);
    } else {
        return -1;
    }

}

void intDiv::revive() {
    if (perminactive) {
        return;
    }
    if (active) {
        perminactive = true;
    } else {
        active = true;
        lastnum = -1;
    }

}

bool intDiv::getActive() {
    return active;
}

void intDiv::reset() {
    perminactive = false;
    active = true;
    lastnum = -1;
}

