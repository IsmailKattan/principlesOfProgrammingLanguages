all: compile connect run

compile: 
	gcc -c -I "./include" ./src/test.c -o ./lib/test.o

connect:
	gcc ./lib/test.o -o ./bin/program

run:
	./bin/program