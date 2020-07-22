a.exe: rps.o main.o
	g++ -g rps.o main.o

rps.o: rps.cpp rps.h
	g++ -c -g rps.cpp

main.o: main.cpp rps.h
	g++ -c -g main.cpp