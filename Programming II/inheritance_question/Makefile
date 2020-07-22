a.exe: main.o question.o choice_question.o
	g++ -g main.o question.o choice_question.o

choice_question.o: choice_question.cpp choice_question.h question.h
	g++ -c -g choice_question.cpp

question.o: question.cpp question.h
	g++ -c -g question.cpp

main.o: main.cpp question.h choice_question.h
	g++ -c -g main.cpp