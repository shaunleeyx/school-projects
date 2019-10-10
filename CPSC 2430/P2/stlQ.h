#ifndef STLQ_H
#define STLQ_H
#include <queue>

class stlQ
{
    public:
        stlQ();
        void Flush();
        void Push(int input);
        void pop();

    private:
    std::queue<int>* Q;
    int counter =0;
};

#endif // STLQ_H
