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

/// @brief creates unique, solvable problems
class BetterGenerator {
 public:
  /// @brief create an engine to generate problems form
  /// @param edgeSize
  BetterGenerator(int edgeSize);
  /// @brief generate unique, solvable problems based on the following parameters
  /// @param numberOfProblems to generate
  /// @param numberOfMisplacedTiles in the puzzle
  /// @param outputFileName
  void generate(int numberOfProblems, int numberOfMisplacedTiles, string outputFileName);

 private:
  // instance variables
  int edgeSize;
  int dimension;
  ofstream myFile;

  /// @brief create a dummy puzzle to simulate some moves and create an inital state
  /// @param numberOfMisplacedTiles number of tiles that should be out of place
  /// @return
  vector<int> createPuzzle(int numberOfMisplacedTiles);

  /// @brief utility function that counts up the number of misplaced tiles
  /// @param arr
  /// @return number of misplaced tiles
  int misplacedTiles(vector<int> arr);

  /// @brief utility function that moves the tiles on the dummy puzzle
  /// @param move
  /// @param p
  /// @return
  bool moveTile(int move, Puzzle& p);

  /// @brief write the puzzle to the output file
  /// @param toWrite
  void writeToFile(vector<int> toWrite);
};

#endif