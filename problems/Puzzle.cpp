#include "Puzzle.h"

Puzzle::Puzzle(vector<int> puzzleArray, int edgeSize) {
  this->puzzleArray = puzzleArray;
  this->edgeSize = edgeSize;
  dimension = (int)puzzleArray.size();
  emptySpaceIndex = getOneDimensionIndex(-1);
}

Puzzle::Puzzle(vector<int> puzzleArray, int edgeSize, int emptySpaceIndex) {
  this->puzzleArray = puzzleArray;
  this->edgeSize = edgeSize;
  this->emptySpaceIndex = emptySpaceIndex;
  dimension = (int)puzzleArray.size();
}

// move tile on bottom into empty space (empty tile goes down)
Puzzle* Puzzle::moveDown() {
  // make a copy of the vector
  vector<int> copy = puzzleArray;

  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first + 1, emptyTwoDim.second);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

// move tile on the left in to empty space (empty tile goes right)
Puzzle* Puzzle::moveLeft() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first, emptyTwoDim.second - 1);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

// move tile on the right in to empty space (empty tile goes right)
Puzzle* Puzzle::moveRight() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first, emptyTwoDim.second + 1);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

// move tile on top into empty space (empty tile goes up)
Puzzle* Puzzle::moveUp() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first - 1, emptyTwoDim.second);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

vector<int> Puzzle::getPuzzleArray() {
  return puzzleArray;
}

int Puzzle::getEdgeSize() {
  return edgeSize;
}

int Puzzle::getDimension() {
  return dimension;
}

int Puzzle::getEmptySpaceIndex() {
  return emptySpaceIndex;
}

// not sure if we want to be using this function very often b/c of runtime
int Puzzle::getOneDimensionIndex(int tileNumber) {
  for (int i = 0; i < dimension; i++) {
    if (puzzleArray[i] == tileNumber) {
      return i;
    }
  }
  return -1;
}

int Puzzle::getOneDimensionIndexFromTwoDimension(int x, int y) {
  return edgeSize * x + y;
}

pair<int, int> Puzzle::getTwoDimensionIndex(int tileNumber) {
  int one = getOneDimensionIndex(tileNumber);
  return getTwoDimensionIndexFromOneDimension(one);
}

pair<int, int> Puzzle::getTwoDimensionIndexFromOneDimension(int oneDimensionIndex) {
  div_t res = div(oneDimensionIndex, edgeSize);
  return (make_pair(res.quot, res.rem));
}

bool Puzzle::canMoveDown(int previousAction) {
  if (previousAction == 4) {
    return false;
  }
  // if the the x is less than edgeSize - 1
  if (getTwoDimensionIndexFromOneDimension(emptySpaceIndex).first < edgeSize - 1) {
    return true;
  }
  return false;
}
bool Puzzle::canMoveLeft(int previousAction) {
  if (previousAction == 3) {
    return false;
  }
  // if the y size is greater than 0
  if (getTwoDimensionIndexFromOneDimension(emptySpaceIndex).second > 0) {
    return true;
  }
  return false;
}
bool Puzzle::canMoveRight(int previousAction) {
  if (previousAction == 2) {
    return false;
  }
  // if the y size is less than edgeSize - 1
  if (getTwoDimensionIndexFromOneDimension(emptySpaceIndex).second < edgeSize - 1) {
    return true;
  }
  return false;
}
bool Puzzle::canMoveUp(int previousAction) {
  if (previousAction == 1) {
    return false;
  }
  // if the x is greater than 0

  if (getTwoDimensionIndexFromOneDimension(emptySpaceIndex).first > 0) {
    return true;
  }
  return false;
}

void Puzzle::printPuzzle() {
  int counter = 0;
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      cout << puzzleArray[counter] << " ";
      counter++;
    }
    cout << endl;
  }
}

void Puzzle::swap(int indexA, int indexB, vector<int>& toSwap) {
  int temp = toSwap[indexA];
  toSwap[indexA] = toSwap[indexB];
  toSwap[indexB] = temp;
}