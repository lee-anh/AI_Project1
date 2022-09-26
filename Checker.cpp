#include "Checker.h"

// @brief check if a given puzzle is the goal state by iterating through and comparing elements with indices
/// @param toCheck
/// @return true if isGoalState, false if not
bool Checker::isGoalState(Puzzle* toCheck) {
  int dimension = (int)toCheck->getPuzzleArray().size();
  for (int i = 0; i < dimension; i++) {
    if (i == 0) {
      if (toCheck->getPuzzleArray()[i] != -1) return false;
    } else {
      if (toCheck->getPuzzleArray()[i] != i) return false;
    }
  }
  return true;
}

/// @brief check if a proposed solution works to get from inital state to goal state
/// follows the proposed solution and executes the moves
/// @param initial state
/// @param proposedSolution solution to check (in reverse order)
/// @return true if isSolution, false if not
bool Checker::isSolution(Puzzle* initial, vector<int> proposedSolution) {
  Puzzle* solution = initial;
  // go backwards
  for (int i = (int)proposedSolution.size() - 1; i >= 0; i--) {
    int move = proposedSolution[i];
    if (move == 1) {
      solution = solution->moveDown();
    } else if (move == 2) {
      solution = solution->moveLeft();
    } else if (move == 3) {
      solution = solution->moveRight();
    } else if (move == 4) {
      solution = solution->moveUp();
    }
  }
  if (Checker::isGoalState(solution)) {
    return true;
  }
  return false;
}