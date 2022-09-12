#include "Loader.h"

// should match with default constructor for ProblemGenerator
Loader::Loader() {
  targetFileName = "test.txt";
  currentProblemNumber = 0;
  openFile();
  readInMetaData();
}
Loader::Loader(string targetFileName) {
  currentProblemNumber = 0;
  this->targetFileName = targetFileName;
  openFile();
  readInMetaData();
}

vector<vector<int>> Loader::getProblem() {
  // TODO: read in the next problem
  vector<vector<int>> toReturn;
  if (myFile.is_open()) {
    string line;
    getline(myFile, line);
    stringstream lineStream(line);

    for (int i = 0; i < edgeSize; i++) {
      vector<int> temp;
      for (int j = 0; j < edgeSize; j++) {
        int tile;
        lineStream >> tile;
        temp.push_back(tile);
      }
      toReturn.push_back(temp);
    }
  }

  /*
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      cout << toReturn[i][j] << " ";
    }
    cout << endl;
  }
  */

  currentProblemNumber++;
  return toReturn;
}

bool Loader::hasNextProblem() {
  if (currentProblemNumber < numberOfProblems) {
    return true;
  }
  return false;
}

void Loader::openFile() {
  myFile.open("./problems/" + targetFileName, ifstream::in);
  if (!myFile) {
    cerr << "Cannot find file named " << targetFileName << " in problems folder" << endl;
    exit(1);
  }
}

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
