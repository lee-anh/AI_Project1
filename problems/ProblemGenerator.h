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
  /// @brief generate puzzles and write to file
  static void generate(int edgeSize, int numberOfProblems, string outputFileName);
  /// @brief generate every permutation of a three puzzle
  static void generateEveryThreePuzzle();
  /// @brief generate every permutation of an eight puzzle
  static void generateEveryEightPuzzle();

 private:
  /// @brief create the numbers and randomize the sequence
  /// @return randomized sequence
  static vector<int> createSequence(int edgeSize);
};

#endif