#ifndef CHECKER
#define CHECKER

#include <iostream>
#include <vector>

using namespace std;

// I feel like the Checker might not even be needed.
// What level will it be used at?
class Checker {
 public:
  Checker();
  bool isGoalState(vector<vector<int>> toCheck);
  // we don't need to know the edge size because we can get it from the array
};

#endif