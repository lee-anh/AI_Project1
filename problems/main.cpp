#include <iostream>
#include <string>
#include <vector>

#include "BetterGenerator.h"
#include "ProblemGenerator.h"

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Time to generate problems!" << endl;
  if (argc < 2) {
    return 0;
  }
  int arg = stoi(argv[1]);

  switch (arg) {
    case 2: {
      // three problems are trivial so we can just generate all of them
      ProblemGenerator::generateEveryThreePuzzle();
      break;
    }
    case 3: {
      BetterGenerator* bg3 = new BetterGenerator(3);
      bg3->generate(100, 6, "test3_6.txt");
      bg3->generate(100, 7, "test3_7.txt");
      bg3->generate(100, 8, "test3_8.txt");
      break;
    }
    case 4: {
      BetterGenerator* bg4 = new BetterGenerator(4);
      bg4->generate(30, 10, "test4_10.txt");
      bg4->generate(30, 11, "test4_11.txt");
      bg4->generate(30, 12, "test4_12.txt");
      // bg4->generate(10, 13, "test4_13.txt");
      // bg4->generate(10, 15, "test4_15.txt");
      break;
    }
    default:
      return 0;
  }

  return 0;
}