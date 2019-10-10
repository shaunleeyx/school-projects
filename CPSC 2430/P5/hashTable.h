// Shaun Lee
// December 3 2018
// version 1
//this is the header of the hash table

#ifndef P5_HASHTABLE_H
#define P5_HASHTABLE_H
#include <iostream>
using namespace std;
class hashTable {
public:
    hashTable();
    ~hashTable();
    void insert(string);
    string search(string);
    string* top();



private:
    struct Node{
        string data;
        Node* next;
        int freq = 0;
    };
    string *array();
    void bubbleSort(string* &arr, int n);
    void swap(string *xp, string *yp);
    void uniquewords();
    int numberofwords = 0;

    int hash(string);

    Node** table;
    const int size = 364169395;
    string punctuationremover(string);
    string toLowerCase(string);

};


#endif //P5_HASHTABLE_H
