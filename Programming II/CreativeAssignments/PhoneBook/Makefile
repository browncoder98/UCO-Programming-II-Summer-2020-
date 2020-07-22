a.exe: tree.o main.o
	g++ -g tree.o main.o

tree.o: tree.cpp tree.h
	g++ -c -g tree.cpp

main.o: main.cpp tree.h
	g++ -c -g main.cpp