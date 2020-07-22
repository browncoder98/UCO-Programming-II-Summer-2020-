a.exe: node.o linkedlist.o main.o
	g++ -g node.o linkedlist.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c -g linkedlist.cpp

main.o: main.cpp linkedlist.h
	g++ -c -g main.cpp