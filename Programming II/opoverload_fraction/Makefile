a.exe: main.o fraction.o
	g++ -g main.o fraction.o

fraction.o: fraction.cpp fraction.h
	g++ -g -c fraction.cpp

main.o: main.cpp fraction.h
	g++ -g -c main.cpp