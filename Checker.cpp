#include "Checker.h"

bool Checker::isGoalState(vector<int> toCheck) {
  int dimension = (int)toCheck.size();
  for (int i = 0; i < dimension; i++) {
    if (i == 0) {
      if (toCheck[i] != -1) return false;
    } else {
      if (toCheck[i] != i) return false;
    }
  }
  return true;
}