//
// Created by Shaun Lee on 11/7/18.
//

#ifndef P4_FLUSHQ_H
#define P4_FLUSHQ_H


class flushQ {
public:
    flushQ();
   void insert(int);
   void printall();
   bool isEmpty();
   int remove();



    void flush(int);

    ~flushQ();
    flushQ(const flushQ& obj );
    flushQ operator+(const flushQ &obj);
    int n = 0;
private:
    void swap(int, int);
    void heapifyDown(int);
    void heapify();
    int size = 10;
    int* array;
    void resize();

};


#endif //P4_FLUSHQ_H
