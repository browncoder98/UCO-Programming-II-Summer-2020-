a.exe: dlink.o main.o
	g++ -g dlink.o main.o

dlink.o: dlink.cpp dlink.h
	g++ -c -g dlink.cpp

main.o: main.cpp dlink.h
	g++ -c -g main.cpp