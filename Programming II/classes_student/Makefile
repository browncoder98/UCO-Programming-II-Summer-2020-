a.exe: main.o student.o
	g++ -g main.o student.o

main.o: main.cpp student.h
	g++ -g -c main.cpp

student.o: student.cpp student.h
	g++ -g -c student.cpp