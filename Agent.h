#ifndef AGENT
#define AGENT

#include <iostream>
#include <queue>
#include <vector>

#include "Checker.h"
#include "Heuristic.h"
#include "Node.h"
#include "NodeCompare.h"

using namespace std;
class Agent {
 public:
  Agent(Node* puzzleRoot, int heuristic);
  // TODO:
  void AStarSearch();
  void expand();

  // TODO: will print meta data and backtrace
  void outputToLog();  // see if we can do some sort of file stream redirection

  int getDeepestDepth();
  int getAverageBranchingFactor();
  int getAverageFrontierSize();

 private:
  Node* root;
  Node* current;
  int deepestDepth;
  int heuristic;
  int sumBranchingFactor;
  int sumFrontierSize;
  int totalNumberOfNodes;
  int totalNumberOfParentNodes;
  priority_queue<Node*, vector<Node*>, NodeCompare> pq;
};

#endif