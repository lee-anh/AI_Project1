# AI_Project1

## A\* Sliding Puzzle Solver

## Claire Liu, CS 420: Artificial Intelligence, Lafayette College, Fall 2022

This is a A\* Sliding Puzzle solver which uses the following heuristics:

- Number of Misplaced Tiles
- Sum of Manhattan Distance
- Number of Swaps from MAXSORT
- Sum of Euclidean Distance

To run the program, first generate problems by running the following in the `problems` folder

```
make three
make eight
make fifteen
```

You can also run `make clean` to remove the .o files and the executable `./generate`

To run the experiment, run the following commands from the project root folder.

```
make three
make eight
make fifteen
```

Note that running make fifteen will take a long time.

You can also run the following commands

```
make clean // remove the .o files and the executable ./p1
make tests // outputs to testHeuristics.txt in problems folder
make cleanLog // deletes all .txt files in the log
```

Additional project details are in the report which is a pdf that is part of this repo.
