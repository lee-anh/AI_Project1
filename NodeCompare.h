#ifndef NODE_COMPARE
#define NODE_COMPARE

#include <iostream>
#include <vector>

#include "Node.h"

using namespace std;

class NodeCompare {
 public:
  bool operator()(Node* a, Node* b);
};

#endif