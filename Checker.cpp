#include "Checker.h"

bool Checker::isGoalState(vector<vector<int>> toCheck) {
  int edgeSize = (int)toCheck.size();
  int counter = 0;
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      if (counter == 0) {
        if (toCheck[i][j] != -1) {
          return false;
        }
      } else {
        if (toCheck[i][j] != counter) {
          return false;
        }
      }
      counter++;
    }
  }
  return true;
}