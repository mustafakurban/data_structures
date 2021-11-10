/** 
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Gruptakilerin yazar adları ve mail adresleri
*/



#include <iostream>
#include <fstream>
#include <string>
#include "node.h"
#include "Parser.h"
#include "Doubly_linked_list_operations.h"


using namespace std;

void print_screen(Node * head)
{
    Node * temp = head;

    while(temp -> next -> next != NULL)
    {
        cout << temp -> data << " <--> "; 
        temp = temp -> next;
    }

    cout << temp -> data << " <--> "; 
    temp = temp -> next;
    cout << temp -> data; 


}



int main()
{
    
    //defining a root for doubly linked list
    Node * root;
    root = new Node();
    root -> next = NULL;
    root -> prev = NULL;

    Node * temp;
    temp=root;

    Parser parser_obj;

    //this class uses for operation in linked list
    Doubly_linked_list_operations dbl_obj;

    //read file line by line
    ifstream file("Veriler.txt");
	string command;

    //load startup node
    getline(file, command);
    parser_obj.main_parser_func(command);
    root -> data = parser_obj.name;


	while (getline(file, command))
    {
        Parser parser_obj;
    	// note that the newline character is not included
        // in the getline() function
        parser_obj.main_parser_func(command);

        //add conditional
        if(parser_obj.operant == "E") dbl_obj.add_node(temp,parser_obj);
        else dbl_obj.delete_node(temp,parser_obj);
    }

    print_screen(root);

	return 0;
}