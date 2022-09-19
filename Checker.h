#ifndef CHECKER
#define CHECKER

#include <iostream>
#include <vector>

#include "Puzzle.h"
using namespace std;

class Checker {
 public:
  static bool isGoalState(Puzzle* toCheck);
};

#endif