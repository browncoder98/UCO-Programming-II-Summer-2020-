a.exe: darray.o main.o
	g++ -g darray.o main.o

darray.o: darray.cpp darray.h
	g++ -c -g darray.cpp

main.o: main.cpp darray.h
	g++ -c -g main.cpp