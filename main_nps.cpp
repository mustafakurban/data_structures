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


using namespace std;


/* Node of a doubly linked list */
class Node
{
    public:
        string data = "#";
        Node* next; // Pointer to next node in DLL
        Node* prev; // Pointer to previous node in DLL
};


class Parser
{
    public:
        string operant = "";
        string name    = "";
        int index      = 0;
        void main_parser_func(string command_line);
        void ekle_parser(string command_line);
        void sil_parser(string command_line);
};
void Parser::main_parser_func(string command_line)
{
    //router
    if(command_line[0] == 'E')
    {
        ekle_parser(command_line);
    }
    if(command_line[0] == 'S')
    {
        sil_parser(command_line);
    }
}
void Parser::ekle_parser(string command_line)
{
    
    //get desired operation
    operant = command_line[0];

    //some veriables for get index
    string temp =  "";
    //we use name_head_holder to understand from which index the name starts inside the string. 
    int name_head_holder = 3;


    for(int i = 2;;i++)
    {
        if(command_line[i] ==  '#')
        {
            break;
        }
        temp = temp + command_line[i];
        name_head_holder++;
    }
    //convert str to int 
    index = stoi(temp);

    //get name
    for(int i = name_head_holder;;i++)
    {
        if(command_line[i] == ')')
        {
            break;
        }

        name = name + command_line[i];

    }
    
    //cout << "operant : " << operant << endl;
    //cout << "index : " << index << endl;
    //cout << "name : " << name;

}
void Parser::sil_parser(string command_line)
{
    operant = command_line[0];

    //some veriables for get index
    string temp =  "";
    //we use name_head_holder to understand from which index the name starts inside the string. 
    int name_head_holder = 3;


    for(int i = 2;;i++)
    {
        if(command_line[i] ==  '#')
        {
            break;
        }
        temp = temp + command_line[i];
    }
    //convert str to int 
    index = stoi(temp);


    //cout << "operant : " << operant << endl;
    //cout << "index : " << index << endl;

}


class Doubly_linked_list_operations
{
    public:
        void add_node(Node * head,Parser fragmented_data);
        void delete_node(Node *head,Parser fragmented_data);
};
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