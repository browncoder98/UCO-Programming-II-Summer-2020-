a.exe: polynomial.o main.o
	g++ -g polynomial.o main.o

polynomial.o: polynomial.cpp polynomial.h
	g++ -c -g polynomial.cpp

main.o: main.cpp polynomial.h
	g++ -c -g main.cpp