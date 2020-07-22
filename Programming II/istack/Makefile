a.exe: node.o istack.o main.o nstack.o
	g++ -g node.o istack.o main.o nstack.o

nstack.o: nstack.cpp nstack.h
	g++ -c -g nstack.cpp

node.o: node.cpp node.h
	g++ -c -g node.cpp

istack.o: istack.cpp istack.h node.h
	g++ -c -g istack.cpp

main.o: main.cpp istack.h 
	g++ -c -g main.cpp


