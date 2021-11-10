#ifndef DOUBLY_LINKED_LIST_OPERATIONS_H
#define DOUBLY_LINKED_LIST_OPERATIONS_H


#include <iostream>
#include <string>
#include "node.h"
#include "Parser.h"



using namespace std;

class Doubly_linked_list_operations
{
    public:
        void add_node(Node * head,Parser fragmented_data);
        void delete_node(Node *head,Parser fragmented_data);
};

#endif // DOUBLY_LINKED_LIST_OPERATIONS_H