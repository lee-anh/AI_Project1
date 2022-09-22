#ifndef PUZZLE
#define PUZZLE

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Puzzle {
 public:
  Puzzle(vector<int> puzzleArray, int edgeSize);
  Puzzle(vector<int> puzzleArray, int edgeSize, int emptySpaceIndex);

  bool canMoveDown(int previousAction);
  bool canMoveLeft(int previousAction);
  bool canMoveRight(int previousAction);
  bool canMoveUp(int previousAction);

  Puzzle* moveDown();
  Puzzle* moveLeft();
  Puzzle* moveRight();
  Puzzle* moveUp();

  vector<int> getPuzzleArray();
  int getEdgeSize();
  int getDimension();
  int getEmptySpaceIndex();

  int getOneDimensionIndex(int tileNumber);
  int getOneDimensionIndexFromTwoDimension(int x, int y);
  pair<int, int> getTwoDimensionIndex(int tileNumber);
  pair<int, int> getTwoDimensionIndexFromOneDimension(int oneDimensionIndex);

  void printPuzzle();

  void swap(int indexA, int indexB, vector<int>& toSwap);

 private:
  vector<int> puzzleArray;
  int edgeSize;
  int dimension;
  int emptySpaceIndex;
};

#endif