#include "Agent.h"

Agent::Agent(Node* puzzleRoot, int heuristic) {
  root = puzzleRoot;
  current = root;
  deepestDepth = 0;
  this->heuristic = heuristic;
  sumBranchingFactor = 0;
  sumFrontierSize = 0;
  totalNumberOfNodes = 1;
  totalNumberOfParentNodes = 1;
  pq.push(root);
}

Node* Agent::AStarSearch() {
  while (!pq.empty()) {
    sumFrontierSize += pq.size();
    current = pq.top();
    pq.pop();
    if (Checker::isGoalState(current->getState())) {
      // TODO:  have some sort of output to the log file?
      outputToLog(current);
      return current;
    }
    expand();
  }
  return NULL;
}

void Agent::expand() {
  int numberOfChildren = 0;
  totalNumberOfParentNodes++;

  Puzzle* currentState = current->getState();
  int previousAction = current->getAction();
  if (currentState->canMoveDown(previousAction)) {
    Puzzle* down = currentState->moveDown();
    numberOfChildren++;
    addChild(down, 1);
  }
  if (currentState->canMoveLeft(previousAction)) {
    Puzzle* left = currentState->moveLeft();
    numberOfChildren++;
    addChild(left, 2);
  }
  if (currentState->canMoveRight(previousAction)) {
    Puzzle* right = currentState->moveRight();
    numberOfChildren++;
    addChild(right, 3);
  }
  if (currentState->canMoveUp(previousAction)) {
    Puzzle* up = currentState->moveUp();
    numberOfChildren++;
    addChild(up, 4);
  }
  sumBranchingFactor += numberOfChildren;
  totalNumberOfNodes += numberOfChildren;
}

void Agent::outputToLog(Node* solution) {
  cout << "Total nodes: " << totalNumberOfNodes << endl
       << "Deepest depth: " << deepestDepth << endl
       << "Average branching factor: " << getAverageBranchingFactor() << endl
       << "Average frontier size: " << getAverageFrontierSize() << endl
       << "Solution node: " << endl;
  solution->printNode();
}

int Agent::getDeepestDepth() {
  return deepestDepth;
}

float Agent::getAverageBranchingFactor() {
  return sumBranchingFactor * 1.0 / totalNumberOfParentNodes;
}

float Agent::getAverageFrontierSize() {
  return sumFrontierSize * 1.0 / totalNumberOfParentNodes;
}

void Agent::addChild(Puzzle* puzzle, int move) {
  int heuristicEstimate = Heuristic::calculateHeuristic(puzzle, heuristic);
  int depth = current->getDepth() + 1;
  Node* toPush = new Node(puzzle, current, move, depth + heuristicEstimate, depth, heuristicEstimate);
  pq.push(toPush);
  toPush->printNode();
  if (depth > deepestDepth) {
    deepestDepth = depth;
  }
}