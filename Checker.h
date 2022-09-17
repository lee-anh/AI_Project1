#ifndef CHECKER
#define CHECKER

#include <iostream>
#include <vector>

using namespace std;

class Checker {
 public:
  Checker();
  bool isGoalState(vector<int> toCheck);
};

#endif