#include "Agent.h"

Agent::Agent(Node* puzzleRoot) {
  root = puzzleRoot;
  current = root;
  deepestDepth = 0;
  sumBranchingFactor = 0;
  int sumFrontierSize = 0;
  totalNumberOfNodes = 1;
  pq.push(root);
}

void Agent::expand() {
  int numberOfChildren = 0;
  Puzzle* down = current->getState()->moveDown();
  Puzzle* left = current->getState()->moveLeft();
  Puzzle* right = current->getState()->moveRight();
  Puzzle* up = current->getState()->moveUp();
  // TODO: I don't think you can check it like this
  if (down != NULL) {
    // TODO: separate this out to a new function
    numberOfChildren++;
    // TODO: cost - I think it might be time to plug in the heuristic
    // int nodeCost =

    // Node* toAdd = new Node(down, current, 1, current->getDepth()+1);
    // create the new node
  }

  // try to move down
  // try to move up
  // try to move left
  // try to move right

  // we must also plug in the heuristic
}

int Agent::getDeepestDepth() {
  return deepestDepth;
}