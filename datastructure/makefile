run:program execute
	
program:main.o Doubly_linked_list_operations.o Parser.o node
	g++  ./lib/main.o ./lib/Doubly_linked_list_operations.o ./lib/Parser.o ./lib/node.o -o ./bin/program
Doubly_linked_list_operations.o:
	g++ -I "./include" -c ./src/Doubly_linked_list_operations.cpp -o ./lib/Doubly_linked_list_operations.o
Parser.o:
	g++ -I "./include" -c ./src/Parser.cpp -o ./lib/Parser.o
main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
node:
	g++ -I "./include" -c ./src/node.cpp -o ./lib/node.o
execute:
	./bin/program.exe