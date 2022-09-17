#ifndef HEURISTIC
#define HEURISTIC

#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;
class Heuristic {
 public:
  Heuristic(int edgeSize, int heuristic);
  int calculateHeuristic(Puzzle* puzzle);

 private:
  int edgeSize;
  int heuristic;

  vector<pair<int, int>> manhattanLookUp;

  // h1: Misplaced Tiles
  int misplacedTiles(Puzzle* puzzle);

  // h2: Manhattan Distance
  void calculateLookUpForManhattanDistance();
  int manhattanDistance(Puzzle* puzzle);

  // h3:
  int maxSort(Puzzle* puzzle);

  // h4:
  int geometricDistance(Puzzle* puzzle);  // might want to return a float?
};

#endif