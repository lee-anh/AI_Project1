#include <iostream>
#include <string>

#include "ProblemGenerator.h"

using namespace std;

int main() {
  cout << "Hello World!" << endl;
  ProblemGenerator *p = new ProblemGenerator();
  p->generate();
  delete (p);
}