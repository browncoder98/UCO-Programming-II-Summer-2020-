a.exe: Bucky.o main.o
	g++ -g Bucky.o main.o

Bucky.o: Bucky.cpp Bucky.h
	g++ -c -g Bucky.cpp

main.o: main.cpp Bucky.h
	g++ -c -g main.cpp
