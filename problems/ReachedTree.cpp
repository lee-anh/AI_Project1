#include "ReachedTree.h"

ReachedTree::ReachedTree() {
  root = new ReachedNode(0);
}

// have to add in the rest of the vector as well
bool ReachedTree::isReached(vector<int> puzzleArray) {
  ReachedNode* current = root;
  // I guess I am going with the iterative approach
  for (int i = 0; i < (int)puzzleArray.size(); i++) {
    int resIndex = hasChild(current, puzzleArray[i]);
    if (resIndex == -1) {
      addRestOfVectorToTree(current, puzzleArray, i);
      return false;
    } else {
      // follow the node path
      current = current->children[resIndex];
      // edge case with nodes that have no children? I don't think we have to worry about that
    }
  }
  return true;
}

// returns the index of the child, -1 if there is no child
int ReachedTree::hasChild(ReachedNode* current, int numberToCheck) {
  for (int i = 0; i < (int)current->children.size(); i++) {
    if (current->children.at(i)->num == numberToCheck) {
      return i;
    }
  }
  return -1;
}

void ReachedTree::addRestOfVectorToTree(ReachedNode* current, vector<int> arrToAdd, int indexToStartAt) {
  ReachedNode* curr = current;
  // I guess we could do recursively but that would have higher runtime
  for (int i = indexToStartAt; i < (int)arrToAdd.size(); i++) {
    ReachedNode* toAdd = new ReachedNode(arrToAdd[i]);
    curr->children.push_back(toAdd);
    curr = toAdd;
  }
}