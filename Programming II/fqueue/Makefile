a.exe: fqueue.o main.o
	g++ -g fqueue.o main.o

fqueue.o: fqueue.cpp fqueue.h
	g++ -c -g fqueue.cpp

main.o: main.cpp fqueue.h
	g++ -c -g main.cpp

	