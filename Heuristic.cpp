#include "Heuristic.h"

int Heuristic::calculateHeuristic(Puzzle* puzzle, int heuristic) {
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
int Heuristic::misplacedTiles(Puzzle* puzzle) {
  int count = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    // actually I think this is counting them wrong
    if (puzzle->getPuzzleArray().at(i) != i) {
      count++;
    }
  }
  // subtract 1 from the total because blank will always be out of place
  return count - 1;
}

// h2: Manhattan Distance
int Heuristic::manhattanDistance(Puzzle* puzzle) {
  int sum = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    int tileNumber = puzzle->getPuzzleArray().at(i);
    pair<int, int> tileCoordinate = puzzle->getTwoDimensionIndexFromOneDimension(tileNumber);
    pair<int, int> target = puzzle->getTwoDimensionIndexFromOneDimension(i);

    int xDiff = abs(tileCoordinate.first - target.first);

    int yDiff = abs(tileCoordinate.second - target.second);
    sum += xDiff + yDiff;
  }
  return sum;
}

// h3:
int Heuristic::maxSort(Puzzle* puzzle) {
  // TODO: implement. pretty vague definition in project description
  int sum = 0;
  return sum;
}

// h4:
int Heuristic::geometricDistance(Puzzle* puzzle) {
  int sum = 0;
  // TODO: implement
  // use the curent classes
  // is this a sum?
  return sum;
}