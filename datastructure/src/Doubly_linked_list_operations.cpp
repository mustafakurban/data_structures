#include "Doubly_linked_list_operations.h"



void Doubly_linked_list_operations::add_node(Node * head,Parser fragmented_data)
{
    int index = fragmented_data.index;
    string name  = fragmented_data.name;

    //allocate new node
    Node * new_node = new Node();
    
    //to access the last node
    Node * temp = head;
    int node_counter = 1;
    
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        node_counter++;
    }

    //valid index checker
    if(index >= node_counter)
    {
        //means the requested index number does not exist in the node tree
        new_node->data = fragmented_data.name;

        //linking process
        new_node->next = NULL;
        new_node->prev = temp;

        temp->next = new_node;

        return;

    }
    else if(index < node_counter)
    {
        //linking process
        new_node->next = NULL;
        new_node->prev = temp;

        temp->next = new_node;

        //Parameters are updated as new node is added
        //node_counter++; -> can be tested and re-added
        temp = temp -> next;

        while(node_counter != index)
        {
            temp -> data = temp -> prev -> data;
            temp = temp -> prev;
            node_counter--;
        }
        temp -> data = name;
                
        return;
    }
}
void Doubly_linked_list_operations::delete_node(Node * head,Parser fragmented_data)
{
    int index = fragmented_data.index;

    //to access the last node
    Node * temp = head;
    int node_counter = 0;
    
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        node_counter++;
    }

    if(node_counter < index)
    {
        Node * temp_prev = temp -> prev;
        delete(temp);
        temp_prev -> next = NULL;
    }

    else if(node_counter >= index){
        
       
        while (node_counter != index) {
            temp = temp-> prev;
            node_counter--;
        }


        while(temp->next != NULL){
            temp->data = temp->next->data;
            temp = temp->next;
        }
        temp = temp->prev;
        delete(temp->next);
        temp->next = NULL;
    }
    
}