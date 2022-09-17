#ifndef HEURISTIC
#define HEURISTIC

#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;
class Heuristic {
 public:
  static int calculateHeuristic(Puzzle* puzzle, int heuristic);

 private:
  // h1: Misplaced Tiles
  static int misplacedTiles(Puzzle* puzzle);

  // h2: Manhattan Distance
  static int manhattanDistance(Puzzle* puzzle);

  // h3:
  static int maxSort(Puzzle* puzzle);

  // h4:
  static int geometricDistance(Puzzle* puzzle);  // might want to return a float?
};

#endif