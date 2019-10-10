// Shaun Lee
// December 3 2018
// version 1
//hash table puts the words into data and then shows most frequent

#include "hashTable.h"

hashTable::hashTable() {
    table = new Node *[size];
    for (int i = 0; i < size; i++) {
        table[i] = NULL;
    }
}

hashTable::~hashTable() {}

string* hashTable::top() {
    string* arr = array();
    bubbleSort(arr,17817);
    return arr;

}

string *hashTable::array() {
    int count = 0;
    string *array = new string[17817];
    for (int i = 0; i < size; i++) {
        if (table[i] != NULL) {
            array[count] = to_string(table[i]->freq) + " " + table[i]->data;
            count++;
        }
    }
    return array;

}

void hashTable::bubbleSort(string* &arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            int a = stoi(arr[j]);
            int b = stoi(arr[j+1]);
            if (a < b)
                swap(&arr[j], &arr[j+1]);
        }

    }

        // Last i elements are already in place

}
void hashTable::swap(string *xp, string *yp)
{
    string temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void hashTable::insert(string x) {
    //Do nothing if x's length is less than 4
    string str = toLowerCase(punctuationremover(x));
    if (str.length() < 4) {
        return;
    }
    int hashint = hash(str);
    //cout << str << ":" << hashint << endl;
    if (table[hashint] == NULL) {
        table[hashint] = new Node();
        table[hashint]->data = str;
        table[hashint]->next = NULL;
        table[hashint]->freq++;
        numberofwords++;

    } else {
        Node *root = table[hashint];
        while (root->next != NULL) {
            root = root->next;
        }
        Node *item = new Node();
        item->data = str;
        root->next = item;
        table[hashint]->freq++;
    }


}

string hashTable::search(string x) {
    int a = hash(x);
return "word:" + table[a]->data + " freq:" + to_string(table[a]->freq);

}

void hashTable::uniquewords() {
    int uniquecount = 0;
    for (int i = 0; i < size; i++) {
        Node *ptr = table[i];
        while (ptr) {
            if (ptr->freq == 1) {
                uniquecount++;
            }
            ptr = ptr->next;
        }
    }
    cout << "uniquecount:" << uniquecount << endl;
}

int hashTable::hash(string name) {


    // UNIX ELF hash
    // Published hash algorithm used in the UNIX ELF format for object files
    unsigned long h = 0, g;
    int value;
    string::iterator sp;

    for (sp = name.begin(); sp != name.end(); sp++) {
        h = (h << 4) + *sp;
        if (g = h & 0xF0000000) {
            h ^= g >> 24;
            h &= ~g;
        }
    }
    value = h;
    return value;

}

string hashTable::punctuationremover(string x)//removes punctuation
{
    for (int i = 0, len = x.size(); i < len; i++)//removes all punctuation
    {
        if (ispunct(x[i])) {
            x.erase(i--, 1);
            len = x.size();
        }
    }
    return x;

    // std::cout << x << endl;
}

string hashTable::toLowerCase(string x) {
    // using transform() function and ::tolower in STL
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    return x;
    //cout << x << endl;
}




