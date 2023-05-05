all: compile connect run

compile: 
	gcc -c -I "./include" -I "./include/tactic" ./src/test.c -o ./lib/test.o
	gcc -c -I "./include" ./src/flag.c -o ./lib/flag.o
	gcc -c -I "./include/tactic" ./src/tactic/tactic.c -o ./lib/tactic/tactic.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticA.c -o ./lib/tactic/tacticA.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticB.c -o ./lib/tactic/tacticB.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticC.c -o ./lib/tactic/tacticC.o

connect:
	gcc ./lib/test.o ./lib/flag.o ./lib/tactic/tactic.o ./lib/tactic/tacticA.o ./lib/tactic/tacticB.o ./lib/tactic/tacticC.o -o ./bin/program

run:
	./bin/program