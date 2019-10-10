#include "LLQ.h"

LLQ::LLQ()
{
head = new Node;
tail = head;
}



void LLQ::Push(int input)
{
tail->link = new Node;
tail->data = input;
counter++;
}

void LLQ:: pop()
{
temp = head;
head = head->link;
delete temp;
}

void LLQ::Flush()
{
temp = head;
current = head;
    if(tail->data > 10)
    {
        for(int i = 0; i < 10; i++)
        {
            if(current->data < 0)
            {
                delptr = current;
                current = current->link;
                temp->link = current;
                delete delptr;
            }

            temp = current;
            current = current->link;
        }

    }

}


