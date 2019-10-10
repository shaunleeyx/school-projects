#ifndef LLQ_H
#define LLQ_H


class LLQ
{
    public:
        LLQ();
        void Flush();
        void Push(int input);
        void pop();

    private:

       struct Node
{
       int	data;
       Node* link;
};
Node* head;
Node* tail;
Node* temp;
Node* current;
Node* delptr;
int counter = 0;

};

#endif // LLQ_H
