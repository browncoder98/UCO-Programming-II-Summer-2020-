a.exe: Heap_PriorityQueue.o main.o
	g++ -g Heap_PriorityQueue.o main.o

Heap_PriorityQueue.o: Heap_PriorityQueue.cpp Heap_PriorityQueue.h
	g++ -c -g Heap_PriorityQueue.cpp

main.o: main.cpp Heap_PriorityQueue.h
	g++ -c -g main.cpp
