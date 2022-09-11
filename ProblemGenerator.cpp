#include "ProblemGenerator.h"

ProblemGenerator::ProblemGenerator() {
  edgeSize = 2;
  numberOfProblems = 1;
  outputFileName = "test.txt";
}

// should we set a maximum number of problems that the user can input?
ProblemGenerator::ProblemGenerator(int edgeSize, int numberOfProblems, string outputFileName) {
  this->edgeSize = edgeSize;
  this->numberOfProblems = numberOfProblems;
  this->outputFileName = outputFileName;
}

void ProblemGenerator::generate() {
  vector<string> toPrint = createSequence();

  // write to a file
  ofstream myFile;

  myFile.open(outputFileName);

  // print out edgeSize once
  myFile << edgeSize << endl;

  // print out all of the tiles
  for (int i = 0; i < (int)toPrint.size(); i++) {
    myFile << toPrint.at(i) << " ";
    if (i != 0 && (i - 1 % edgeSize == 0)) {
      myFile << endl;
    }
  }
  myFile.close();
}

vector<string> ProblemGenerator::createSequence() {
  vector<string> toReturn;
  int numberOfNumbers = edgeSize * edgeSize - 1;
  for (int i = 0; i < numberOfNumbers; i++) {
    toReturn.push_back(to_string(i + 1));
  }
  // # will denote the blank space until read in
  toReturn.push_back("#");
  // TODO: make sure the numbers generated are unique
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(toReturn.begin(), toReturn.end(), default_random_engine(seed));
  return toReturn;
}
