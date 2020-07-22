a.exe: main.o baseball.o stats.o wordguess.o
	g++ -g main.o baseball.o stats.o wordguess.o

main.o: main.cpp baseball.h stats.h wordguess.h
	g++ -g -c main.cpp

baseball.o: baseball.cpp baseball.h
	g++ -g -c baseball.cpp

stats.o: stats.cpp stats.h
	g++ -g -c stats.cpp

wordguess.o: wordguess.cpp wordguess.h
	g++ -g -c wordguess.cpp