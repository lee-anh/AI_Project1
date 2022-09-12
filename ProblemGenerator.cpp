#include "ProblemGenerator.h"

/// @brief Default Constructor
ProblemGenerator::ProblemGenerator() {
  edgeSize = 2;
  numberOfProblems = 1;
  outputFileName = "test.txt";
}

// should we set a maximum number of problems that the user can input?

/// @brief Constructor
/// @param edgeSize puzzle dimension
/// @param numberOfProblems to generate
/// @param outputFileName file to create/write to
ProblemGenerator::ProblemGenerator(int edgeSize, int numberOfProblems, string outputFileName) {
  this->edgeSize = edgeSize;
  this->numberOfProblems = numberOfProblems;
  this->outputFileName = outputFileName;
}

/// @brief generate puzzles and write to file
void ProblemGenerator::generate() {
  ofstream myFile;
  myFile.open("./problems/" + outputFileName);

  myFile << edgeSize << " " << numberOfProblems << endl;

  // for how many puzzles you want to generate
  for (int i = 0; i < numberOfProblems; i++) {
    // print out all of the tiles
    vector<int> toPrint = createSequence();
    for (int j = 0; j < (int)toPrint.size(); j++) {
      myFile << toPrint.at(j) << " ";
    }
    myFile << endl;
  }

  myFile.close();
}

/// @brief create the numbers and randomize the sequence
/// @return randomized sequence
vector<int> ProblemGenerator::createSequence() {
  vector<int> toReturn;
  int numberOfNumbers = edgeSize * edgeSize - 1;
  for (int i = 0; i < numberOfNumbers; i++) {
    toReturn.push_back(i + 1);
  }
  // -1 will denote the blank space until read in
  toReturn.push_back(-1);
  // TODO: make sure the numbers generated are unique
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(toReturn.begin(), toReturn.end(), default_random_engine(seed));
  return toReturn;
}
