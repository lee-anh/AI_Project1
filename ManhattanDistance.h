#ifndef MANHATTAN_DISTANCE
#define MANHATTAN_DISTANCE

#include <iostream>
#include <vector>

#include "Solver.h"

using namespace std;

class ManhattanDistance {
 public:
  // ManhattanDistance();
  ManhattanDistance(vector<vector<int>> board);
  int calculateHeuristic();

 private:
  vector<vector<int>> board;
  int edgeSize;
  vector<pair<int, int>> lookUp;

  void calculateLookUp();
  int lookUpManhattanDistance(int tile, int x, int y);
};

#endif