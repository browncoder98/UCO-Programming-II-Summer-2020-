a.exe: pqueue.o main.o
	g++ -g pqueue.o main.o

pqueue.o: pqueue.cpp pqueue.h
	g++ -c -g pqueue.cpp

main.o: main.cpp pqueue.h
	g++ -c -g main.cpp