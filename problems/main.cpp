#include <iostream>
#include <string>
#include <vector>

#include "ProblemGenerator.h"

using namespace std;

int main() {
  cout << "Time to generate problems!" << endl;
  string file = "three.txt";
  ProblemGenerator *p = new ProblemGenerator(3, 10, file);
  p->generate();
  return 0;
}