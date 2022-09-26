#include "Puzzle.h"

/// @brief Create a puzzle given the puzzleArray and edge size
/// @param puzzleArray the arrangement of the tiles
/// @param edgeSize the edge size which is sqrt(n+1)
Puzzle::Puzzle(vector<int> puzzleArray, int edgeSize) {
  this->puzzleArray = puzzleArray;
  this->edgeSize = edgeSize;
  dimension = (int)puzzleArray.size();
  emptySpaceIndex = getOneDimensionIndex(-1);
}

/// @brief Create a puzzle given the puzzleArray, edge size, and emptySpace index if it is known
/// @param puzzleArray the arrangement of the tiles
/// @param edgeSize the edge size which is sqrt(n+1)
/// @param emptySpaceIndex the 1d index of where -1, which represents the blank tile, is
Puzzle::Puzzle(vector<int> puzzleArray, int edgeSize, int emptySpaceIndex) {
  this->puzzleArray = puzzleArray;
  this->edgeSize = edgeSize;
  this->emptySpaceIndex = emptySpaceIndex;
  dimension = (int)puzzleArray.size();
}

/// @brief check to see if it is legal for the puzzle to move the blank space down
/// check the previous action to save some computational time in checking for reached states
/// @param previousAction action the agent took to get to this state
/// @return true if move down is an applicable move, false if not
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

/// @brief check to see if it is legal for the puzzle to move the blank space left
/// check the previous action to save some computational time in checking for reached states
/// @param previousAction action the agent took to get to this state
/// @return true if move left is an applicable move, false if not
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

/// @brief check to see if it is legal for the puzzle to move the blank space right
/// check the previous action to save some computational time in checking for reached states
/// @param previousAction action the agent took to get to this state
/// @return true if move right is an applicable move, false if not
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

/// @brief check to see if it is legal for the puzzle to move the blank space up
/// check the previous action to save some computational time in checking for reached states
/// @param previousAction action the agent took to get to this state
/// @return true if move up is an applicable move, false if not
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

/// @brief move tile on bottom into empty space (empty tile goes down)
/// @return the resulting state
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

/// @brief move tile on the left in to empty space (empty tile goes right)
/// @return the resulting state
Puzzle* Puzzle::moveLeft() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first, emptyTwoDim.second - 1);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

/// @brief move tile on the right in to empty space (empty tile goes right)
/// @return the resulting state
Puzzle* Puzzle::moveRight() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first, emptyTwoDim.second + 1);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

/// @brief move tile on top into empty space (empty tile goes up)
/// @return the resulting state
Puzzle* Puzzle::moveUp() {
  vector<int> copy = puzzleArray;
  pair<int, int> emptyTwoDim = getTwoDimensionIndexFromOneDimension(emptySpaceIndex);
  // index to swap will be the new emptySpaceIndex
  int indexToSwap = getOneDimensionIndexFromTwoDimension(emptyTwoDim.first - 1, emptyTwoDim.second);
  swap(emptySpaceIndex, indexToSwap, copy);
  // create the new puzzle
  return new Puzzle(copy, edgeSize, indexToSwap);
}

/// @brief getter for the puzzle array
/// @return
vector<int> Puzzle::getPuzzleArray() {
  return puzzleArray;
}

/// @brief getter for the edge size
/// @return
int Puzzle::getEdgeSize() {
  return edgeSize;
}

/// @brief getter for the puzzle's 1d vector size
/// @return
int Puzzle::getDimension() {
  return dimension;
}

/// @brief getter for the blank space's 1d index
/// @return
int Puzzle::getEmptySpaceIndex() {
  return emptySpaceIndex;
}

/// @brief find the one dimensional index for a given tile number
/// @param tileNumber to find the one dimensional index of
/// @return the one dimensional index
int Puzzle::getOneDimensionIndex(int tileNumber) {
  for (int i = 0; i < dimension; i++) {
    if (puzzleArray[i] == tileNumber) {
      return i;
    }
  }
  return -1;
}

/// @brief utility function to calculate the one dimensional index from the two dimensional index
/// @param x
/// @param y
/// @return one dimensional index
int Puzzle::getOneDimensionIndexFromTwoDimension(int x, int y) {
  return edgeSize * x + y;
}

/// @brief utility function to calculate the two dimensional index givent he
/// @param tileNumber
/// @return
pair<int, int> Puzzle::getTwoDimensionIndex(int tileNumber) {
  int one = getOneDimensionIndex(tileNumber);
  return getTwoDimensionIndexFromOneDimension(one);
}

/// @brief utility function to get get a two dimensional index given a one dimensional index
/// @param oneDimensionIndex
/// @return
pair<int, int> Puzzle::getTwoDimensionIndexFromOneDimension(int oneDimensionIndex) {
  div_t res = div(oneDimensionIndex, edgeSize);
  return (make_pair(res.quot, res.rem));
}

/// @brief print the puzzle array to cout
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

/// @brief swap elements in a 1d vector
/// @param indexA index of element to swap
/// @param indexB index of element to swap
/// @param toSwap vector where the elements to swap are

void Puzzle::swap(int indexA, int indexB, vector<int>& toSwap) {
  int temp = toSwap[indexA];
  toSwap[indexA] = toSwap[indexB];
  toSwap[indexB] = temp;
}