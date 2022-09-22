#include <iostream>
#include <string>
#include <vector>

#include "BetterGenerator.h"
#include "ProblemGenerator.h"

using namespace std;

int main() {
  cout << "Time to generate problems!" << endl;
  // BetterGenerator* bg3 = new BetterGenerator(3);
  // bg3->generate(100, 7, "testy.txt");
  BetterGenerator* bg2 = new BetterGenerator(3);
  bg2->generate(100, 6, "test3_6.txt");
  // bg3->generate(5, 5, "testy.txt");
  //  ProblemGenerator::generateEveryThreePuzzle();
  //  ProblemGenerator::generateEveryEightPuzzle();
  return 0;
}