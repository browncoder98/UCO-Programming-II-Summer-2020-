a.exe: fstack.o main.o
	g++ -g fstack.o main.o

fstack.o: fstack.cpp fstack.h
	g++ -g -c fstack.cpp

main.o: main.cpp fstack.h
	g++ -g -c main.cpp