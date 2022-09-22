#include "Agent.h"

Agent::Agent(Node* puzzleRoot, int heuristic, string outputFileName) {
  root = puzzleRoot;
  current = root;
  deepestDepth = 0;
  this->heuristic = heuristic;
  this->outputFileName = outputFileName;
  sumBranchingFactor = 0;
  sumFrontierSize = 0;
  timeToSolve = 0;
  totalNumberOfNodes = 1;
  totalNumberOfParentNodes = 1;
  pq.push(root);
  reached = new ReachedTree();
}

Node* Agent::AStarSearch() {
  auto start = chrono::high_resolution_clock::now();
  while (!pq.empty()) {
    sumFrontierSize += pq.size();
    current = pq.top();
    pq.pop();
    if (Checker::isGoalState(current->getState())) {
      auto stop = chrono::high_resolution_clock::now();
      auto duration = duration_cast<chrono::microseconds>(stop - start);
      timeToSolve = duration.count();
      outputToLog(current, true);
      return current;
    }
    expand();
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = duration_cast<chrono::microseconds>(stop - start);
  timeToSolve = duration.count();
  outputToLog(current, false);
  return NULL;
}

void Agent::addChild(Puzzle* puzzle, int move) {
  // don't add the node if we've seen this state before
  if (reached->isReached(puzzle->getPuzzleArray())) {
    return;
  }
  int heuristicEstimate = Heuristic::calculateHeuristic(puzzle, heuristic);
  int depth = current->getDepth() + 1;
  Node* toPush = new Node(puzzle, current, move, depth + heuristicEstimate, depth, heuristicEstimate);
  pq.push(toPush);
  // toPush->printNode();
  if (depth > deepestDepth) {
    deepestDepth = depth;
  }
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

int Agent::getDeepestDepth() {
  return deepestDepth;
}

float Agent::getAverageBranchingFactor() {
  return sumBranchingFactor * 1.0 / totalNumberOfParentNodes;
}

float Agent::getAverageFrontierSize() {
  return sumFrontierSize * 1.0 / totalNumberOfParentNodes;
}

// TODO: need a backtrace of the solution?
void Agent::outputToLog(Node* solution, bool solved) {
  ofstream myFile;
  myFile.open(outputFileName, ios_base::app);
  myFile << timeToSolve << "\t" << getAverageBranchingFactor() << "\t"
         << getAverageFrontierSize() << "\t" << totalNumberOfNodes << "\t" << solved << endl;
  myFile.close();
}
