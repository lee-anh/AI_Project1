#ifndef NODE
#define NODE

#include <iostream>
#include <vector>

#include "Puzzle.h"

using namespace std;

/// @brief represents a state
class Node {
 public:
  /// @brief Construct a state
  /// @param state tile arrangement
  /// @param parentNode
  /// @param action the parent took to get to the state
  /// @param cost estimated cost of this state f(n)
  /// @param depth g(n) initial state to this state
  /// @param heuristicEstimate h(n)
  Node(Puzzle* state, Node* parentNode, int action, float cost, int depth, int heuristicEstimate);

  /// @brief getter for state of tile arrangement
  /// @return
  Puzzle* getState();

  /// @brief getter for parent node
  /// @return
  Node* getParentNode();

  /// @brief getter for action parent took to get to this state
  /// @return
  int getAction();

  /// @brief getter for f(n)
  /// @return
  float getCost();

  /// @brief getter for g(n)
  /// @return
  int getDepth();

  /// @brief getter for h(n)
  /// @return
  int getHeuristicEstimate();

  /// @brief print node contents to cout
  void printNode();

 private:
  // instance variables
  Puzzle* state;
  Node* parentNode;
  int action;
  float cost;
  int depth;
  int heuristicEstimate;
};

#endif