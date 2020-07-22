a.exe: node.o deque.o main.o
	g++ -g node.o deque.o main.o

node.o: node.cpp node.h
	g++ -c -g node.cpp

deque.o: deque.cpp deque.h node.h
	g++ -c -g deque.cpp

main.o: main.cpp deque.h
	g++ -c -g main.cpp