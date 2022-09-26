#include "Node.h"

/// @brief Construct a state
/// @param state tile arrangement
/// @param parentNode
/// @param action the parent took to get to the state
/// @param cost estimated cost of this state f(n)
/// @param depth g(n) initial state to this state
/// @param heuristicEstimate h(n)
Node::Node(Puzzle* state, Node* parentNode, int action, float cost, int depth, int heuristicEstimate) {
  this->state = state;
  this->parentNode = parentNode;
  this->action = action;
  this->cost = cost;
  this->depth = depth;
  this->heuristicEstimate = heuristicEstimate;
}

/// @brief getter for state of tile arrangement
/// @return
Puzzle* Node::getState() {
  return state;
}

/// @brief getter for parent node
/// @return
Node* Node::getParentNode() {
  return parentNode;
}

/// @brief getter for action parent took to get to this state
/// @return
int Node::getAction() {
  return action;
}

/// @brief getter for f(n)
/// @return
float Node::getCost() {
  return cost;
}

/// @brief getter for g(n)
/// @return
int Node::getDepth() {
  return depth;
}

/// @brief getter for h(n)
/// @return
int Node::getHeuristicEstimate() {
  return heuristicEstimate;
}

/// @brief print node contents to cout
void Node::printNode() {
  cout << "State:" << endl;
  state->printPuzzle();
  cout << "Action: " << action << endl
       << "Cost: " << cost << endl
       << "Depth: " << depth << endl
       << "h(n): " << heuristicEstimate << endl
       << endl;
}
