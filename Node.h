#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;

class Node {
 public:
  Node(Puzzle* state, Node* parentNode, int action, int cost, int depth);

  Puzzle* getState();
  Node* getParentNode();
  int getAction();
  int getCost();
  int getDepth();

  void setState(Puzzle* state);
  void setParentNode(Node* parent);
  void setAction(int action);
  void setCost(int cost);
  void setDepth(int depth);

 private:
  Puzzle* state;
  Node* parentNode;
  int action;
  int cost;
  int depth;
};

#endif