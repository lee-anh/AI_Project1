#include "BetterGenerator.h"

/// @brief create an engine to generate problems form
/// @param edgeSize
BetterGenerator::BetterGenerator(int edgeSize) {
  this->edgeSize = edgeSize;
  dimension = edgeSize * edgeSize;
}

/// @brief generate unique, solvable problems based on the following parameters
/// @param numberOfProblems to generate
/// @param numberOfMisplacedTiles in the puzzle
/// @param outputFileName
void BetterGenerator::generate(int numberOfProblems, int numberOfMisplacedTiles, string outputFileName) {
  if (numberOfMisplacedTiles > dimension - 1) {
    cerr << "too many misplaced tiles requested." << endl;
    return;
  }
  ReachedTree* reached = new ReachedTree();
  int numberGenerated = 0;
  myFile.open(outputFileName);
  // output metadata
  myFile << edgeSize << " " << numberOfProblems << endl;

  // sometimes number of problems requested will be too large... how will we catch that?
  while (numberGenerated < numberOfProblems) {
    vector<int> proposed = createPuzzle(numberOfMisplacedTiles);
    if (reached->isReached(proposed) == false) {
      writeToFile(proposed);
      numberGenerated++;
    }
  }
  myFile.close();
}

/// @brief create a dummy puzzle to simulate some moves and create an inital state
/// @param numberOfMisplacedTiles number of tiles that should be out of place
/// @return
vector<int> BetterGenerator::createPuzzle(int numberOfMisplacedTiles) {
  // populate the puzzle array
  vector<int> puzzleArray;
  for (int i = 0; i < dimension; i++) {
    if (i == 0) {
      puzzleArray.push_back(-1);
    } else {
      puzzleArray.push_back(i);
    }
  }

  // random device
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> distribution(1, 4);

  Puzzle p = Puzzle(puzzleArray, edgeSize);

  // keep generating until you get something that matches
  while (misplacedTiles(p.getPuzzleArray()) < numberOfMisplacedTiles) {
    moveTile(distribution(gen), p);
  }

  // cout << "# misplaced: " << misplacedTiles(p.getPuzzleArray()) << endl;

  return p.getPuzzleArray();
}

/// @brief utility function that counts up the number of misplaced tiles
/// @param arr
/// @return number of misplaced tiles
int BetterGenerator::misplacedTiles(vector<int> arr) {
  int count = 0;
  for (int i = 0; i < (int)arr.size(); i++) {
    if (arr.at(i) != i) {
      count++;
    }
  }
  // -1 is always out of place
  return count - 1;
}

/// @brief utility function that moves the tiles on the dummy puzzle
/// @param move
/// @param p
/// @return
bool BetterGenerator::moveTile(int move, Puzzle& puzzle) {
  // cout << "Before: " << endl;
  // puzzle.printPuzzle();
  // cout << "After: " << endl;
  if (move == 1) {
    if (puzzle.canMoveDown(0)) {
      puzzle = *puzzle.moveDown();
      // puzzle.printPuzzle();

      return true;
    }
    return false;
  } else if (move == 2) {
    if (puzzle.canMoveLeft(0)) {
      puzzle = *puzzle.moveLeft();
      // puzzle.printPuzzle();

      return true;
    }
    return false;
  } else if (move == 3) {
    if (puzzle.canMoveRight(0)) {
      puzzle = *puzzle.moveRight();
      //  puzzle.printPuzzle();

      return true;
    }
    return false;
  }
  // else case
  if (puzzle.canMoveUp(0)) {
    puzzle = *puzzle.moveUp();
    return true;
  }
  return false;
}

/// @brief write the puzzle to the output file
/// @param toWrite
void BetterGenerator::writeToFile(vector<int> toWrite) {
  for (int n : toWrite) {
    myFile << n << " ";
  }
  myFile << endl;
}
