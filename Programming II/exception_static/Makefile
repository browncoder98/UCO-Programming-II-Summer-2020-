a.exe: ex1.o student.o
	g++ -g ex1.o student.o

student.o: student.cpp student.h
	g++ -c -g student.cpp

ex1.o: ex1.cpp student.h
	g++ -c ex1.cpp

ex2.exe: ex2.cpp
	g++ -g ex2.cpp -o ex2.exe

3: ex3.o student.o
	g++ -g ex3.o student.o -o 3.exe

ex3.o: ex3.cpp student.h
	g++ -c -g ex3.cpp