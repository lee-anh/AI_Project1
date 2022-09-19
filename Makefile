CC = g++
CFLAGS = -g -Wall -std=c++20

OBJS = main.o Agent.o Checker.o ExperimentController.o Heuristic.o Loader.o Puzzle.o Node.o NodeCompare.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o p1 *.o 
clean:
	rm ./p1
	rm *.o 

main.o: main.cpp ExperimentController.h 
	$(CC) $(CFLAGS) -c main.cpp

Agent.o: Agent.cpp Agent.h Checker.h Heuristic.h Node.h NodeCompare.h
	$(CC) $(CFLAGS) -c Agent.cpp 

Checker.o: Checker.cpp Checker.h Puzzle.h
	$(CC) $(CFLAGS) -c Checker.cpp

ExperimentController.o: ExperimentController.cpp ExperimentController.h Agent.h Loader.h
	$(CC) $(CFLAGS) -c ExperimentController.cpp

Heuristic.o: Heuristic.cpp Heuristic.h Puzzle.h 
	$(CC) $(CFLAGS) -c Heuristic.cpp 

Loader.o: Loader.cpp Loader.h
	$(CC) $(CFLAGS) -c Loader.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	$(CC) $(CFLAGS) -c Puzzle.cpp

Node.o: Node.cpp Node.h Puzzle.h
	$(CC) $(CFLAGS) -c Node.cpp 

NodeCompare.o: NodeCompare.cpp NodeCompare.h
	$(CC) $(CFLAGS) -c NodeCompare.cpp