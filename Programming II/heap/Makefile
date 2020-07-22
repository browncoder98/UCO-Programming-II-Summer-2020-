a.exe: heap.o main.o
	g++ -g heap.o main.o

heap.o: heap.cpp heap.h
	g++ -c -g heap.cpp

main.o: main.cpp heap.h
	g++ -c -g main.cpp
