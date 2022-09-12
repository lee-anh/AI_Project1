#include <iostream>
#include <string>
#include <vector>

#include "Loader.h"
#include "ManhattanDistance.h"
#include "ProblemGenerator.h"

using namespace std;

int main() {
  cout << "Hello World!" << endl;
  string file = "three.txt";
  ProblemGenerator *p = new ProblemGenerator(3, 10, file);
  p->generate();
  Loader *l = new Loader(file);
  l->getProblem();
  vector<vector<int>> toTest;
  toTest.push_back({7, 2, 4});
  toTest.push_back({
      5,
      -1,
      6,
  });
  toTest.push_back({8, 3, 1});
  ManhattanDistance *md = new ManhattanDistance(toTest);
  cout << "md " << md->calculateHeuristic() << endl;
}