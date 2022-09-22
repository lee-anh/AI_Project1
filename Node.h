#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;

class Node {
 public:
  Node(Puzzle* state, Node* parentNode, int action, float cost, int depth, int heuristicEstimate);

  Puzzle* getState();
  Node* getParentNode();
  int getAction();
  float getCost();
  int getDepth();
  int getHeuristicEstimate();

  void printNode();

 private:
  Puzzle* state;
  Node* parentNode;
  int action;
  float cost;
  int depth;
  int heuristicEstimate;
};

#endif