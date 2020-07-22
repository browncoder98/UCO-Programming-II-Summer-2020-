a.exe: node.o bstree.o main.o
	g++ -g node.o bstree.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

bstree.o: bstree.cpp bstree.h node.h
	g++ -c -g bstree.cpp

main.o: main.cpp bstree.h
	g++ -c -g main.cpp