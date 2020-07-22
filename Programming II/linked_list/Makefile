a.exe: node.o list.o main.o listiterator.o
	g++ -g node.o list.o main.o listiterator.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

listiterator.o: listiterator.cpp listiterator.h node.h list.h
	g++ -c -g listiterator.cpp

list.o: list.cpp list.h node.h
	g++ -c -g list.cpp

main.o: main.cpp list.h 
	g++ -c -g main.cpp
