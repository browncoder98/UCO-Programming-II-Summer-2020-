a.exe: stack.o main.o
	g++ -g stack.o main.o

stack.o: stack.cpp stack.h
	g++ -c -g stack.cpp

main.o: main.cpp stack.h
	g++ -c -g main.cpp