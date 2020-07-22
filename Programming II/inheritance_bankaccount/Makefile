a.exe: bankaccount.o main.o checkingaccount.o savingsaccount.o
	g++ -g bankaccount.o main.o checkingaccount.o savingsaccount.o

savingsaccount.o: savingsaccount.cpp savingsaccount.h bankaccount.h
	g++ -c -g savingsaccount.cpp

checkingaccount.o: checkingaccount.cpp checkingaccount.h bankaccount.h
	g++ -c -g checkingaccount.cpp

bankaccount.o: bankaccount.cpp bankaccount.h
	g++ -c -g bankaccount.cpp

main.o: main.cpp bankaccount.h
	g++ -c -g main.cpp