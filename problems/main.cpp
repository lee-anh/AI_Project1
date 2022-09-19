#include <iostream>
#include <string>
#include <vector>

#include "ProblemGenerator.h"

using namespace std;

int main() {
  cout << "Time to generate problems!" << endl;
  ProblemGenerator::generateEveryThreePuzzle();
  ProblemGenerator::generateEveryEightPuzzle();
  return 0;
}