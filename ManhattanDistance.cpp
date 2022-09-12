#include "ManhattanDistance.h"

ManhattanDistance::ManhattanDistance(vector<vector<int>> board) {
  this->board = board;
  edgeSize = (int)board.size();
  calculateLookUp();
}

int ManhattanDistance::calculateHeuristic() {
  int dist = 0;
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      dist += lookUpManhattanDistance(board[i][j], i, j);
    }
  }
  return dist;
}

void ManhattanDistance::calculateLookUp() {
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      lookUp.push_back(make_pair(i, j));
    }
  }
}

// TODO: test this
int ManhattanDistance::lookUpManhattanDistance(int tile, int x, int y) {
  // case: empty space = -1
  if (tile == -1) {
    return 0;
  }
  pair<int, int> target = lookUp.at(tile);
  int xDiff = abs(x - target.first);
  int yDiff = abs(y - target.second);
  return xDiff + yDiff;
}