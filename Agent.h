#ifndef AGENT
#define AGENT

#include <iostream>
#include <queue>
#include <vector>

#include "Node.h"
#include "NodeCompare.h"

using namespace std;
class Agent {
 public:
  Agent(Node* puzzleRoot);
  void expand();

  void AStarSearch();
  // will print meta data and backtrace
  void outputToLog();

  int getDeepestDepth();
  int getAverageBranchingFactor();
  int getAverageFrontierSize();

 private:
  Node* root;
  Node* current;
  // where do we plug in the heuristic?
  // where do we plug in the checker?

  // do we really want to compute these
  // or can we just have a running total and then take care of it there

  int deepestDepth;
  int sumBranchingFactor;
  int sumFrontierSize;
  int totalNumberOfNodes;

  // need to make a priority_queue which has Nodes for comparator
  priority_queue<Node*, vector<Node*>, NodeCompare> pq;
};

#endif