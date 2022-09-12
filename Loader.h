#ifndef LOADER
#define LOADER

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Loader {
 public:
  Loader();
  Loader(string targetFileName);
  // ~Loader(); // not sure if we need a destructor yet
  vector<vector<int>> getProblem();
  bool hasNextProblem();

 private:
  // instance variables
  int currentProblemNumber;
  int edgeSize;
  ifstream myFile;
  int numberOfProblems;
  string targetFileName;

  void openFile();
  void readInMetaData();
  void closeFile();
};

#endif