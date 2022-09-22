#ifndef BETTER_GENERATOR
#define BETTER_GENERATOR

#include <time.h>

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Puzzle.h"
#include "ReachedTree.h"

using namespace std;

class BetterGenerator {
 public:
  BetterGenerator(int edgeSize);
  void generate(int numberOfProblems, int numberOfMisplacedTiles, string outputFileName);

 private:
  int edgeSize;
  int dimension;
  ofstream myFile;

  // int readInFromFile(int dimension, string inputFileName);

  vector<int> createPuzzle(int numberOfMisplacedTiles);
  // utility function
  int misplacedTiles(vector<int> arr);
  bool moveTile(int move, Puzzle& p);

  void writeToFile(vector<int> toWrite);
};

#endif