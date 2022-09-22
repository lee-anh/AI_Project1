#include "BetterGenerator.h"

BetterGenerator::BetterGenerator(int edgeSize) {
  this->edgeSize = edgeSize;
  dimension = edgeSize * edgeSize;
}

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

/*
int BetterGenerator::readInFromFile(int dimension, string inputFileName, ReachedTree* reached) {
  ifstream myFile.open(inputFileName);
  string line;
  int count = 0;

  while (getLine(cin, line)) {
    vector<int> toCheck;
    for (int i = 0; i < dimension; i++) {
      int tile;
      lineStream >> tile;
      toCheck.push_back(tile);
    }
    if (reached->isReached(toCheck) == false) {
      count++;
    }
  }
  return count;
}
*/

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

  // # of misplacedTiles valid swaps

  Puzzle p = Puzzle(puzzleArray, edgeSize);
  // p.printPuzzle();

  // some ways to optimize
  // we would never go over right?
  // don't undo the previous action
  // or just ignore by plugging in 0 it's ok for now
  // save some computation power
  /*
  for (int i = 0; i < numberOfMisplacedTiles; i++) {
    // randomly generate a move 1-4 and move the tile
    moveTile(distribution(gen), p);
  }

   // hardly ever will be triggered
  if (numberOfMisplacedTiles == misplacedTiles(p.getPuzzleArray())) {
    return p.getPuzzleArray();
  }
  if (numberOfMisplacedTiles < misplacedTiles(p.getPuzzleArray())) {
    cerr << "too many misplaced tileS!!!" << endl;
  }*/

  // keep generating until you get something that matches
  while (misplacedTiles(p.getPuzzleArray()) < numberOfMisplacedTiles) {
    moveTile(distribution(gen), p);
  }

  // cout << "# misplaced: " << misplacedTiles(p.getPuzzleArray()) << endl;

  return p.getPuzzleArray();
}

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

// ugh I feel like I might have over complicated this
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

void BetterGenerator::writeToFile(vector<int> toWrite) {
  for (int n : toWrite) {
    myFile << n << " ";
  }
  myFile << endl;
}
