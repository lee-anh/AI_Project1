#include "Node.h"

Node::Node(Puzzle* state, Node* parentNode, int action, int cost, int depth, int heuristicEstimate) {
  this->state = state;
  this->parentNode = parentNode;
  this->action = action;
  this->cost = cost;
  this->depth = depth;
  this->heuristicEstimate = heuristicEstimate;
}

Puzzle* Node::getState() {
  return state;
}
Node* Node::getParentNode() {
  return parentNode;
}
int Node::getAction() {
  return action;
}
int Node::getCost() {
  return cost;
}
int Node::getDepth() {
  return depth;
}
int Node::getHeuristicEstimate() {
  return heuristicEstimate;
}

void Node::printNode() {
  cout << "State:" << endl;
  state->printPuzzle();
  cout << "Action: " << action << endl
       << "Cost: " << cost << endl
       << "Depth: " << depth << endl
       << "h(n): " << heuristicEstimate << endl
       << endl;
}
