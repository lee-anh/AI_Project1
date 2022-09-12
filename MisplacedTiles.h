#ifndef MISPLACED_TILES
#define MISPLACED_TILES

#include <iostream>
#include <vector>

#include "Solver.h"

using namespace std;

class MisplacedTiles {
 public:
  // MisplacedTiles(); // TODO: ok to not have a default constructor?
  MisplacedTiles(vector<vector<int>> board);
  int calculateHeuristic();
  // number of misplaced tiles (blank not included)
 private:
  vector<vector<int>> board;
  int edgeSize;

  // I'm not really sure how this is going to work with the inheritance stuff
};

#endif