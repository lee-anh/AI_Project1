#include "NodeCompare.h"

// TODO: not tested, hopefully this works
// might need to flip!
// don't forget to use print statements
bool NodeCompare::operator()(Node* a, Node* b) {
  return a->getCost() > b->getCost();
}
