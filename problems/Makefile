CC = g++
CFLAGS = -g -Wall -std=c++20

OBJS = main.o BetterGenerator.o Loader.o ProblemGenerator.o Puzzle.o ReachedTree.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o generate *.o 
	./generate 
	
clean:
	rm ./generate
	rm *.o 

main.o: main.cpp BetterGenerator.h ProblemGenerator.h 
	$(CC) $(CFLAGS) -c main.cpp

BetterGenerator.o: BetterGenerator.cpp BetterGenerator.h 
	$(CC) $(CFLAGS) -c BetterGenerator.cpp

Loader.o: Loader.cpp Loader.h
	$(CC) $(CFLAGS) -c Loader.cpp

ProblemGenerator.o: ProblemGenerator.cpp ProblemGenerator.h
	$(CC) $(CFLAGS) -c ProblemGenerator.cpp

Puzzle.o: Puzzle.cpp Puzzle.h
	$(CC) $(CFLAGS) -c Puzzle.cpp

ReachedTree.o: ReachedTree.cpp ReachedTree.h 
	$(CC) $(CFLAGS) -c ReachedTree.cpp 