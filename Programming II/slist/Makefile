a.exe: node.o slist.o main.o
	g++ -g node.o slist.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

slist.o: slist.cpp slist.h
	g++ -c -g slist.cpp

main.o: main.cpp slist.h
	g++ -c -g main.cpp