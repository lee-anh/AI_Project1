#include <iostream>
#include <string>
#include <vector>

#include "Loader.h"

using namespace std;

int main() {
  cout << "Hello World!" << endl;
  string file = "three.txt";
  Loader *l = new Loader(file);
  l->getProblem();
  l->getProblem();
  vector<vector<int>> toTest;
  toTest.push_back({7, 2, 4});
  toTest.push_back({
      5,
      -1,
      6,
  });
  toTest.push_back({8, 3, 1});

  return 0;
}