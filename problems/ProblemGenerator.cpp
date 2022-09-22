#include "ProblemGenerator.h"

/// @brief generate puzzles and write to file
void ProblemGenerator::generate(int edgeSize, int numberOfProblems, string outputFileName) {
  ofstream myFile;
  myFile.open("./" + outputFileName);

  myFile << edgeSize << " " << numberOfProblems << endl;

  // for how many puzzles you want to generate
  for (int i = 0; i < numberOfProblems; i++) {
    // print out all of the tiles
    vector<int> toPrint = createSequence(edgeSize);
    for (int j = 0; j < (int)toPrint.size(); j++) {
      myFile << toPrint.at(j) << " ";
    }
    myFile << endl;
  }

  myFile.close();
}

void ProblemGenerator::generateEveryThreePuzzle() {
  //  4! = 24
  ofstream myFile;
  myFile.open("./every_three_puzzle.txt");
  int arr[] = {-1, 1, 2, 3};
  do {
    myFile << arr[0] << " " << arr[1] << " "
           << arr[2] << " " << arr[3] << endl;
  } while (next_permutation(arr, arr + 4));
}

void ProblemGenerator::generateEveryEightPuzzle() {
  //  8! = 362880
  ofstream myFile;
  myFile.open("./every_eight_puzzle.txt");
  int arr[] = {-1, 1, 2, 3, 4, 5, 6, 7, 8};
  do {
    myFile << arr[0] << " " << arr[1] << " " << arr[2] << " "
           << arr[3] << " " << arr[4] << " " << arr[5] << " "
           << arr[6] << " " << arr[7] << " " << arr[8] << endl;
  } while (next_permutation(arr, arr + 9));
}

/// @brief create the numbers and randomize the sequence
/// @return randomized sequence
vector<int> ProblemGenerator::createSequence(int edgeSize) {
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

// maybe from here we should select the problems
// we need a way to check for old states as well