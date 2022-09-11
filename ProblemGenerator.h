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
  ProblemGenerator();
  ProblemGenerator(int edgeSize, int numberOfProblems, string outputFileName);
  void generate();

 private:
  // instance variables
  int edgeSize;
  int numberOfProblems;
  string outputFileName;

  vector<string> createSequence();
};

#endif