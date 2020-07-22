a.exe: tictactoe.o main.o
	g++ -g tictactoe.o main.o

tictactoe.o: tictactoe.cpp tictactoe.h
	g++ -c -g tictactoe.cpp

main.o: main.cpp tictactoe.h
	g++ -c -g main.cpp