a.exe: main.o myutil.o
	g++ -g main.o myutil.o

myutil.o: myutil.cpp myutil.h
	g++ -c -g myutil.cpp

main.o: main.cpp myutil.h
	g++ -c -g main.cpp