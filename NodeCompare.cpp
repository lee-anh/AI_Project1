#include "NodeCompare.h"

bool NodeCompare::operator()(Node* a, Node* b) {
  return a->getCost() > b->getCost();
}
