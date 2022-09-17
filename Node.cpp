#include "Node.h"

Node::Node(Puzzle* state, Node* parentNode, int action, int cost, int depth) {
  this->state = state;
  this->parentNode = parentNode;
  this->action = action;
  this->cost = cost;
  this->depth = depth;
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

void Node::setState(Puzzle* state) {
  this->state = state;
}
void Node::setParentNode(Node* parent) {
  parentNode = parent;
}
void Node::setAction(int action) {
  this->action = action;
}
void Node::setCost(int cost) {
  this->cost = cost;
}
void Node::setDepth(int depth) {
  this->depth = depth;
}
