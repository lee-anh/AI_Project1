#ifndef HEURISTIC
#define HEURISTIC

#include <cmath>
#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;

/// @brief static class with heuristics
class Heuristic {
 public:
  /// @brief calculate an estimate based on a specified heuristic 
  /// @param puzzle puzzle to calculate a heuristic for 
  /// @param heuristic to calculate 
  /// @return 
  static float calculateHeuristic(Puzzle* puzzle, int heuristic);

 private:
  /// @brief h1: Misplaced Tiles
  /// @param puzzle to estimate
  /// @return heuristic estimate 
  static float misplacedTiles(Puzzle* puzzle);

  /// @brief h2: Manhattan Distance
  /// @param puzzle to estimate
  /// @return heuristic estimate 
  static float manhattanDistance(Puzzle* puzzle);

  /// @brief h3: MAXSORT
  /// @param puzzle to estimate 
  /// @return heuristic estimate 
  static float maxSort(Puzzle* puzzle);

  /// @brief h4: Euclidean Distance 
  /// @param puzzle to estimate 
  /// @return heuristic estimate 
  static float geometricDistance(Puzzle* puzzle); 
};

#endif