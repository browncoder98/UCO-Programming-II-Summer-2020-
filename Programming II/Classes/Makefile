a.exe: main.o bankaccount.o 
	g++ -g main.o bankaccount.o

bankaccount.o: bankaccount.cpp bankaccount.h 
	g++ -g -c bankaccount.cpp

main.o: main.cpp bankaccount.h
	g++ -g -c main.cpp

