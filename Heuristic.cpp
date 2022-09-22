#include "Heuristic.h"

float Heuristic::calculateHeuristic(Puzzle* puzzle, int heuristic) {
  // do you think the order of the switch statement could matter?
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

// h1: Misplaced Tiles
float Heuristic::misplacedTiles(Puzzle* puzzle) {
  int count = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    // actually I think this is counting them wrong
    if (puzzle->getPuzzleArray().at(i) != i) {
      count++;
    }
  }
  // subtract 1 from the total because blank will always be out of place
  return (count - 1);
}

// h2: Manhattan Distance
float Heuristic::manhattanDistance(Puzzle* puzzle) {
  int sum = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    int tileNumber = puzzle->getPuzzleArray().at(i);
    if (tileNumber != -1) {  // don't count the blank tile
      pair<int, int> tileCoordinate = puzzle->getTwoDimensionIndexFromOneDimension(tileNumber);
      pair<int, int> target = puzzle->getTwoDimensionIndexFromOneDimension(i);

      int xDiff = abs(tileCoordinate.first - target.first);

      int yDiff = abs(tileCoordinate.second - target.second);
      sum += xDiff + yDiff;
    }
  }
  return sum;
}

// h3: Euclidean Distance
float Heuristic::maxSort(Puzzle* puzzle) {
  int sum = 0;
  vector<int> puzzleArr = puzzle->getPuzzleArray();
  for (int i = (puzzle->getDimension() - 1); i >= 1; i--) {
    int max = 0;
    for (int j = 1; j < i; j++) {
      if (puzzleArr.at(max) < puzzleArr.at(j)) {
        max = j;
      }
      // swap
      int temp = puzzleArr.at(max);
      puzzleArr.at(max) = puzzleArr.at(i);
      puzzleArr.at(i) = temp;
    }
  }

  return sum;
}

// h4:
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