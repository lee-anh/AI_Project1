CC = g++
CFLAGS = -g -Wall -std=c++20

OBJS = main.o Checker.o ExperimentController.o Loader.o ManhattanDistance.o MisplacedTiles.o ProblemGenerator.o Solver.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o p1 *.o 
clean:
	rm ./p1
	rm *.o 

main.o: main.cpp Loader.h ManhattanDistance.h ProblemGenerator.h
	$(CC) $(CFLAGS) -c main.cpp

Checker.o: Checker.cpp Checker.h
	$(CC) $(CFLAGS) -c Checker.cpp

ExperimentController.o: ExperimentController.cpp ExperimentController.h
	$(CC) $(CFLAGS) -c ExperimentController.cpp

Loader.o: Loader.cpp Loader.h
	$(CC) $(CFLAGS) -c Loader.cpp

ManhattanDistance.o: ManhattanDistance.cpp ManhattanDistance.h
	$(CC) $(CFLAGS) -c ManhattanDistance.cpp

MisplacedTiles.o: MisplacedTiles.cpp MisplacedTiles.h
	$(CC) $(CFLAGS) -c MisplacedTiles.cpp

ProblemGenerator.o: ProblemGenerator.cpp ProblemGenerator.h
	$(CC) $(CFLAGS) -c ProblemGenerator.cpp

Solver.o: Solver.cpp Solver.h
	$(CC) $(CFLAGS) -c Solver.cpp
