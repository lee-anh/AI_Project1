#ifndef HEURISTIC
#define HEURISTIC

#include <cmath>
#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;
class Heuristic {
 public:
  static float calculateHeuristic(Puzzle* puzzle, int heuristic);

 private:
  // h1: Misplaced Tiles
  static float misplacedTiles(Puzzle* puzzle);

  // h2: Manhattan Distance
  static float manhattanDistance(Puzzle* puzzle);

  // h3:
  static float maxSort(Puzzle* puzzle);

  // h4:
  static float geometricDistance(Puzzle* puzzle);  // might want to return a float?
};

#endif