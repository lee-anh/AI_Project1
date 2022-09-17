#include "Agent.h"

Agent::Agent(Node* puzzleRoot, int heuristic) {
  root = puzzleRoot;
  current = root;
  deepestDepth = 0;
  this->heuristic = heuristic;
  sumBranchingFactor = 0;
  sumFrontierSize = 0;
  totalNumberOfNodes = 1;
  totalNumberOfParentNodes = 0;
  pq.push(root);
}

void Agent::AStarSearch() {
}

void Agent::expand() {
  int numberOfChildren = 0;
  totalNumberOfParentNodes++;

  Puzzle* currentState = current->getState();

  if (currentState->canMoveDown()) {
    Puzzle* down = currentState->moveDown();
    numberOfChildren++;
    Node* toPush = new Node(down, current, 1, current->getDepth() + Heuristic::calculateHeuristic(down, heuristic), current->getDepth() + 1);
    pq.push(toPush);
  }
  if (currentState->canMoveLeft()) {
    Puzzle* left = currentState->moveLeft();
    numberOfChildren++;
    Node* toPush = new Node(left, current, 2, current->getDepth() + Heuristic::calculateHeuristic(left, heuristic), current->getDepth() + 1);
    pq.push(toPush);
  }
  if (currentState->canMoveRight()) {
    Puzzle* right = currentState->moveRight();
    numberOfChildren++;
    Node* toPush = new Node(right, current, 3, current->getDepth() + Heuristic::calculateHeuristic(right, heuristic), current->getDepth() + 1);
    pq.push(toPush);
  }
  if (currentState->canMoveUp()) {
    Puzzle* up = currentState->moveUp();
    numberOfChildren++;
    Node* toPush = new Node(up, current, 4, current->getDepth() + Heuristic::calculateHeuristic(up, heuristic), current->getDepth() + 1);
    pq.push(toPush);
  }
  sumBranchingFactor += numberOfChildren;
}

int Agent::getDeepestDepth() {
  return deepestDepth;
}

int Agent::getAverageBranchingFactor() {
  return sumBranchingFactor / totalNumberOfParentNodes;
}

int Agent::getAverageFrontierSize() {
  return sumFrontierSize / totalNumberOfParentNodes;
}