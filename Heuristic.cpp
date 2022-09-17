#include "Heuristic.h"
Heuristic::Heuristic(int edgeSize, int heuristic) {
  this->edgeSize = edgeSize;
  this->heuristic = heuristic;

  // any set up
  if (heuristic == 2) {
    calculateLookUpForManhattanDistance();
  }
}

int Heuristic::calculateHeuristic(Puzzle* puzzle) {
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
void Heuristic::calculateLookUpForManhattanDistance() {
  // what it should be
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      manhattanLookUp.push_back(make_pair(i, j));
    }
  }
}
int Heuristic::manhattanDistance(Puzzle* puzzle) {
  int sum = 0;
  for (int i = 0; i < puzzle->getDimension(); i++) {
    int tileNumber = puzzle->getPuzzleArray().at(i);
    pair<int, int> tileCoordinate = puzzle->getTwoDimensionIndexFromOneDimension(i);
    pair<int, int> target = manhattanLookUp.at(tileNumber);
    int xDiff = abs(tileCoordinate.first - target.first);
    int yDiff = abs(tileCoordinate.second - target.second);
    sum += xDiff + yDiff;
  }
  return sum;
}

// h3:
int Heuristic::maxSort(Puzzle* puzzle) {
  // TODO: implement. pretty vague definition in project description

  return 0;
}

// h4:
int Heuristic::geometricDistance(Puzzle* puzzle) {
  int sum = 0;
  // TODO: implement
  // use the curent classes
  // is this a sum?
  return sum;
}