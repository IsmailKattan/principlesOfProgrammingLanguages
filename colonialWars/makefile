all: compile connect run

compile:
	gcc -c -I "./include" -I "./include/production" -I "./include/tactic" ./src/test.c -o ./lib/test.o
	gcc -c -I "./include" ./src/flag.c -o ./lib/flag.o
	gcc -c -I "./include/production" ./src/production/production.c -o ./lib/production.o
	gcc -c -I "./include/production" ./src/production/productionA.c -o ./lib/productionA.o
	gcc -c -I "./include/production" ./src/production/productionB.c -o ./lib/productionB.o
	gcc -c -I "./include/production" ./src/production/productionC.c -o ./lib/productionC.o
	gcc -c -I "./include/production" ./src/production/productionsUnion.c -o ./lib/productionsUnion.o
	gcc -c -I "./include/tactic" ./src/tactic/tactic.c -o ./lib/tactic.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticA.c -o ./lib/tacticA.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticB.c -o ./lib/tacticB.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticC.c -o ./lib/tacticC.o
	gcc -c -I "./include/tactic" ./src/tactic/tacticsUnion.c -o ./lib/tacticsUnion.o
	gcc -c -I "./include" -I "./include/production" -I "./include/tactic" ./src/colony.c -o ./lib/colony.o
	gcc -c -I "./include" -I "./include/production" -I "./include/tactic" ./src/play.c -o ./lib/play.o
	gcc -c -I "./include" -I "./include/production" -I "./include/tactic" ./src/dynamicArray.c -o ./lib/dynamicArray.o
connect:
	gcc ./lib/dynamicArray.o ./lib/play.o ./lib/colony.o ./lib/tacticsUnion.o ./lib/tacticC.o ./lib/tacticB.o ./lib/tacticA.o ./lib/tactic.o ./lib/flag.o ./lib/productionsUnion.o ./lib/productionC.o ./lib/productionB.o ./lib/productionA.o ./lib/production.o ./lib/test.o -o ./bin/program
run:
	./bin/program