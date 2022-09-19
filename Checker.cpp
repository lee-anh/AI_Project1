#include "Checker.h"

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