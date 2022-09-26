#ifndef NODE_COMPARE
#define NODE_COMPARE

#include <iostream>
#include <vector>

#include "Node.h"

using namespace std;

/// @brief utility class for priority queue in Agent
class NodeCompare {
 public:
  /// @brief overload operator
  /// @param a to compare
  /// @param b to compare
  /// @return
  bool operator()(Node* a, Node* b);
};

#endif