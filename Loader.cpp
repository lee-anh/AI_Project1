#include "Loader.h"

/// @brief default constructor
Loader::Loader() {
  targetFileName = "test.txt";
  currentProblemNumber = 0;
  openFile();
  readInMetaData();
}

/// @brief create Loader object to parse target file
/// @param targetFileName input file to parse
Loader::Loader(string targetFileName) {
  currentProblemNumber = 0;
  this->targetFileName = targetFileName;
  openFile();
  readInMetaData();
}

/// @brief getter for edge size
/// @return
int Loader::getEdgeSize() {
  return edgeSize;
}

/// @brief get the next problem in the file
/// @return
vector<int> Loader::getProblem() {
  vector<int> toReturn;
  if (myFile.is_open()) {
    string line;
    getline(myFile, line);
    stringstream lineStream(line);
    int dimension = edgeSize * edgeSize;

    for (int i = 0; i < dimension; i++) {
      int tile;
      lineStream >> tile;
      toReturn.push_back(tile);
    }
  }

  currentProblemNumber++;
  return toReturn;
}

/// @brief check if the file has another problem
/// @return true if there is another problem, false if not
bool Loader::hasNextProblem() {
  if (currentProblemNumber < numberOfProblems) {
    return true;
  }
  // close the file if there are no other problems
  myFile.close();
  return false;
}

/// @brief getter for number of problems
/// @return
int Loader::getNumberOfProblems() {
  return numberOfProblems;
}

/// @brief open file to parse
void Loader::openFile() {
  myFile.open("./problems/" + targetFileName, ifstream::in);
  if (!myFile) {
    cerr << "Cannot find file named " << targetFileName << " in problems folder" << endl;
    exit(1);
  }
}

/// @brief read in meta data: edgeSize and number of problems
void Loader::readInMetaData() {
  if (myFile.is_open()) {
    string line;
    getline(myFile, line);
    stringstream lineStream(line);
    string str1, str2;
    lineStream >> edgeSize;
    lineStream >> numberOfProblems;

  } else {
    cout << targetFileName + " is not open" << endl;
  }
}
