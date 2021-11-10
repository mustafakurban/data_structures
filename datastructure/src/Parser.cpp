#include "Parser.h"


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