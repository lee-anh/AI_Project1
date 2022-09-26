#ifndef LOADER
#define LOADER

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/// @brief parse input file
class Loader {
 public:
  /// @brief default constructor
  Loader();
  /// @brief create Loader object to parse target file
  /// @param targetFileName input file to parse
  Loader(string targetFileName);

  /// @brief getter for edge size
  /// @return
  int getEdgeSize();

  /// @brief get the next problem in the file
  /// @return
  vector<int> getProblem();

  /// @brief check if the file has another problem
  /// @return true if there is another problem, false if not
  bool hasNextProblem();

  /// @brief getter for number of problems
  /// @return
  int getNumberOfProblems();

 private:
  // instance variables
  int currentProblemNumber;
  int edgeSize;
  ifstream myFile;
  int numberOfProblems;
  string targetFileName;

  /// @brief open file to parse
  void openFile();
  /// @brief read in meta data: edgeSize and number of problems
  void readInMetaData();
};

#endif