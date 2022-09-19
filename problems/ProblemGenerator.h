#ifndef PROBLEM_GENERATOR
#define PROBLEM_GENERATOR

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class ProblemGenerator {
 public:
  static void generate(int edgeSize, int numberOfProblems, string outputFileName);
  static void generateEveryThreePuzzle();  // Loader might have to randomize
  static void generateEveryEightPuzzle();  // Loader might have to randomize

 private:
  static vector<int> createSequence(int edgeSize);
};

#endif