CC = g++
CFLAGS = -g -Wall -std=c++20

OBJS = main.o ProblemGenerator.o

all: $(OBJS)
	$(CC) $(CFLAGS) -o generate *.o 
clean:
	rm ./generate
	rm *.o 

main.o: main.cpp ProblemGenerator.h
	$(CC) $(CFLAGS) -c main.cpp

ProblemGenerator.o: ProblemGenerator.cpp ProblemGenerator.h
	$(CC) $(CFLAGS) -c ProblemGenerator.cpp

