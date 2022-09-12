#include "MisplacedTiles.h"

MisplacedTiles::MisplacedTiles(vector<vector<int>> board) {
  this->board = board;  // hmmm I wonder if this will still work
  edgeSize = (int)board.size();
}

int MisplacedTiles::calculateHeuristic() {
  int count = 0;
  int misplaced = 0;
  for (int i = 0; i < edgeSize; i++) {
    for (int j = 0; j < edgeSize; j++) {
      // don't count the empty tile (-1) as misplaced
      if (count != 0 && board[i][j] != count && board[i][j] != -1) {
        misplaced++;
      }
      count++;
    }
  }
  return misplaced;
}
