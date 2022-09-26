#ifndef PUZZLE
#define PUZZLE

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/// @brief Puzzle class encapsulates the abstraction for an n-Puzzle
class Puzzle {
 public:
  /// @brief Create a puzzle given the puzzleArray and edge size
  /// @param puzzleArray the arrangement of the tiles
  /// @param edgeSize the edge size which is sqrt(n+1)
  Puzzle(vector<int> puzzleArray, int edgeSize);
  /// @brief Create a puzzle given the puzzleArray, edge size, and emptySpace index if it is known
  /// @param puzzleArray the arrangement of the tiles
  /// @param edgeSize the edge size which is sqrt(n+1)
  /// @param emptySpaceIndex the 1d index of where -1, which represents the blank tile, is
  Puzzle(vector<int> puzzleArray, int edgeSize, int emptySpaceIndex);

  /// @brief check to see if it is legal for the puzzle to move the blank space down
  /// @param previousAction action the agent took to get to this state
  /// @return
  bool canMoveDown(int previousAction);

  /// @brief check to see if it is legal for the puzzle to move the blank space left
  /// @param previousAction action the agent took to get to this state
  /// @return
  bool canMoveLeft(int previousAction);

  /// @brief check to see if it is legal for the puzzle to move the blank space right
  /// @param previousAction action the agent took to get to this state
  /// @return
  bool canMoveRight(int previousAction);

  /// @brief check to see if it is legal for the puzzle to move the blank space up
  /// @param previousAction action the agent took to get to this state
  /// @return
  bool canMoveUp(int previousAction);

  /// @brief move the blank tile down
  /// @return the resulting state
  Puzzle* moveDown();

  /// @brief move the blank tile left

  Puzzle* moveLeft();

  /// @brief move the blank tile right
  /// @return the resulting state
  Puzzle* moveRight();

  /// @brief move the blank tile up
  /// @return the resulting state
  Puzzle* moveUp();

  /// @brief getter for the puzzle array
  /// @return
  vector<int> getPuzzleArray();

  /// @brief getter for the edge size
  /// @return
  int getEdgeSize();

  /// @brief getter for the puzzle's 1d vector size
  /// @return
  int getDimension();

  /// @brief getter for the blank space's 1d index
  /// @return
  int getEmptySpaceIndex();

  /// @brief find the one dimensional index for a given tile number
  /// @param tileNumber to find the one dimensional index of
  /// @return the one dimensional index
  int getOneDimensionIndex(int tileNumber);

  /// @brief utility function to calculate the one dimensional index from the two dimensional index
  /// @param x
  /// @param y
  /// @return one dimensional index
  int getOneDimensionIndexFromTwoDimension(int x, int y);

  /// @brief utility function to calculate the two dimensional index givent he
  /// @param tileNumber
  /// @return
  pair<int, int> getTwoDimensionIndex(int tileNumber);

  /// @brief utility function to get get a two dimensional index given a one dimensional index
  /// @param oneDimensionIndex
  /// @return
  pair<int, int> getTwoDimensionIndexFromOneDimension(int oneDimensionIndex);

  /// @brief print the puzzle array to cout
  void printPuzzle();

  /// @brief swap elements in a 1d vector
  /// @param indexA index of element to swap
  /// @param indexB index of element to swap
  /// @param toSwap vector where the elements to swap are
  void swap(int indexA, int indexB, vector<int>& toSwap);

 private:
  // instance variables
  vector<int> puzzleArray;
  int edgeSize;
  int dimension;
  int emptySpaceIndex;
};

#endif