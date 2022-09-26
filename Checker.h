#ifndef CHECKER
#define CHECKER

#include <iostream>
#include <vector>

#include "Puzzle.h"
using namespace std;

/// @brief static class that serves as an answer key 
class Checker {
 public:

  /// @brief check if a given puzzle is the goal state 
  /// @param toCheck 
  /// @return true if isGoalState, false if not 
  static bool isGoalState(Puzzle* toCheck);

  /// @brief check if a proposed solution works to get from inital state to goal state 
  /// @param initial state 
  /// @param proposedSolution solution to check (in reverse order)
  /// @return true if isSolution, false if not
  static bool isSolution(Puzzle* initial, vector<int> proposedSolution);
};

#endif