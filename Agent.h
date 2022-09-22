#ifndef AGENT
#define AGENT

#include <chrono>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "Checker.h"
#include "Heuristic.h"
#include "Node.h"
#include "NodeCompare.h"
#include "ReachedTree.h"

using namespace std;
class Agent {
 public:
  Agent(Node* puzzleRoot, int heuristic, string outputFileName);
  Node* AStarSearch();

 private:
  Node* root;
  Node* current;
  int deepestDepth;
  int heuristic;
  string outputFileName;
  int sumBranchingFactor;
  int sumFrontierSize;
  int timeToSolve;
  int totalNumberOfNodes;
  int totalNumberOfParentNodes;
  priority_queue<Node*, vector<Node*>, NodeCompare> pq;
  ReachedTree* reached;

  void addChild(Puzzle* puzzle, int move);
  void expand();
  int getDeepestDepth();
  float getAverageBranchingFactor();
  float getAverageFrontierSize();
  void outputToLog(Node* solution, bool solved);
};

#endif