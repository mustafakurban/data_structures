#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <string>



using namespace std;

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

#endif // PARSER_H