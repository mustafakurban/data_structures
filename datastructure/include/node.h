#ifndef NODE_H
#define NODE_H


#include <iostream>

using namespace std;

/* Node of a doubly linked list */
class Node
{
    public:
        string data;
        Node* next; // Pointer to next node in DLL
        Node* prev; // Pointer to previous node in DLL
};


#endif // NODE_H