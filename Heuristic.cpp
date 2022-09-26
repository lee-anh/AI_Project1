#include "Heuristic.h"

/// @brief calculate an estimate based on a specified heuristic
/// uses a switch to decide which heuristic to use
/// @param puzzle puzzle to calculate a heuristic for
/// @param heuristic to calculate
/// @return
float Heuristic::calculateHeuristic(Puzzle* puzzle, int heuristic) {
  switch (heuristic) {
    case 1:
      return misplacedTiles(puzzle);
      break;
    case 2:
      return manhattanDistance(puzzle);
      break;
    case 3:
      return maxSort(puzzle);
      break;
    case 4:
      return geometricDistance(puzzle);
      break;
    default:
      return misplacedTiles(puzzle);
  }
}

/// @brief h1: Misplaced Tiles
/// linearly counts up the tiles that are misplace (not including the blank)
/// @param puzzle to estimate
/// @return heuristic estimate
float Heuristic::misplacedTiles(Puzzle* puzzle) {
  int count = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    if (puzzle->getPuzzleArray().at(i) != i) {
      count++;
    }
  }
  // subtract 1 from the total because blank will always be out of place, don't count it
  return (count - 1);
}

/// @brief h2: Manhattan Distance
/// linearly computes the Manhattan distance for each tile (not including the blank)
/// and returns the sum of all the manhattan distances
/// @param puzzle to estimate
/// @return heuristic estimate
float Heuristic::manhattanDistance(Puzzle* puzzle) {
  int sum = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    int tileNumber = puzzle->getPuzzleArray().at(i);
    if (tileNumber != -1) {  // don't count the blank
      pair<int, int> tileCoordinate = puzzle->getTwoDimensionIndexFromOneDimension(tileNumber);
      pair<int, int> target = puzzle->getTwoDimensionIndexFromOneDimension(i);
      int xDiff = abs(tileCoordinate.first - target.first);
      int yDiff = abs(tileCoordinate.second - target.second);
      sum += xDiff + yDiff;
    }
  }
  return sum;
}

/// @brief h3: MAXSORT
/// quadratically sorts the puzzle array and returns the total number of swaps
/// @param puzzle to estimate
/// @return heuristic estimate
float Heuristic::maxSort(Puzzle* puzzle) {
  int numberOfSwaps = 0;
  vector<int> puzzleArr = puzzle->getPuzzleArray();
  for (int i = (puzzle->getDimension() - 1); i >= 1; i--) {
    int max = 0;
    for (int j = 1; j <= i; j++) {
      if (puzzleArr.at(max) < puzzleArr.at(j)) {
        max = j;
      }
    }
    // swap if out of place
    if (puzzleArr.at(max) != puzzleArr.at(i)) {
      int temp = puzzleArr.at(max);
      puzzleArr.at(max) = puzzleArr.at(i);
      puzzleArr.at(i) = temp;
      numberOfSwaps++;
    }
  }
  return numberOfSwaps;
}

/// @brief h4: Euclidean Distance
/// uses the distance formula, returns the sum of all the euclidean distances
/// @param puzzle to estimate
/// @return heuristic estimate
float Heuristic::geometricDistance(Puzzle* puzzle) {
  float sum = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    int tileNumber = puzzle->getPuzzleArray().at(i);
    if (tileNumber != -1) {  // don't count the blank tile
      pair<int, int> tileCoordinate = puzzle->getTwoDimensionIndexFromOneDimension(tileNumber);
      pair<int, int> target = puzzle->getTwoDimensionIndexFromOneDimension(i);
      int xDiff = abs(tileCoordinate.first - target.first);
      int yDiff = abs(tileCoordinate.second - target.second);
      // distance formula
      sum += sqrt(pow(xDiff, 2) + pow(yDiff, 2));
    }
  }

  return sum;
}