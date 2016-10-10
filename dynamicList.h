/*
    Shacobe Johnson
    Computer Science 340
    Section 02
    Lab 5
*/
#include <iostream>
#include <string>
using namespace std;

const int defmaxlistsize=50;

class dynamicList   
{
public:
    dynamicList();		
    dynamicList(int maxnumber);
    ~dynamicList();   	
    bool Full() const;
    bool Empty() const;
    void Getlast(int &item, bool &found);
    bool Insert(int item);
    bool Insert(int item, int location);
    void Remove(int &item, bool &found);
    void Remove(int &item, bool &found,int location);
    bool Search(int item, int &location);
    bool Search(int item);
    void Clear();
    void Print() const;
    int currentSize() const;

private:
    int *element;
    int length;
    int size;
};


