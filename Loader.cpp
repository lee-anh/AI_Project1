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

int Loader::getEdgeSize() {
  return edgeSize;
}

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

    for (int i = 0; i < dimension; i++) {
      cout << toReturn[i] << " ";
    }
  }

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
