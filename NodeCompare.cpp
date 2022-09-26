#include "NodeCompare.h"

/// @brief overload operator
/// @param a to compare
/// @param b to compare
/// @return
bool NodeCompare::operator()(Node* a, Node* b) {
  return a->getCost() > b->getCost();
}
