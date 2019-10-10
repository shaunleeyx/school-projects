#include "stlQ.h"
#include <queue>


stlQ::stlQ()
{
    Q = new std::queue<int>;
}

void stlQ::Push(int input)
{
Q->push(input);
}

void stlQ:: pop()
{
Q->pop();
}

void stlQ::Flush()
{
    for (int i = 0; i <10 ; i++)
    {
        if(Q[counter] < 0)
        {

        }
    }
}