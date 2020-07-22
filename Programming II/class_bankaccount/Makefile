a.exe: person.o bankaccount.o main.o
	g++ -g person.o bankaccount.o main.o

person.o: person.cpp person.h
	g++ -c -g person.cpp

bankaccount.o: bankaccount.cpp bankaccount.h person.h
	g++ -c -g bankaccount.cpp

main.o: main.cpp bankaccount.h
	g++ -c -g main.cpp
	