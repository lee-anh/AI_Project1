#include "ReachedTree.h"

ReachedTree::ReachedTree() {
  root = new ReachedNode(0);
}

/// @brief check to see if the puzzleArray has been reached before
  /// @param puzzleArray
  /// @return 
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

/// @brief check to see if a certain node has a child with a certain number
  /// @param current node to check children of 
  /// @param numberToCheck number we're looking for 
  /// @return the index of the child, -1 if there is no child
int ReachedTree::hasChild(ReachedNode* current, int numberToCheck) {
  for (int i = 0; i < (int)current->children.size(); i++) {
    if (current->children.at(i)->num == numberToCheck) {
      return i;
    }
  }
  return -1;
}


/// @brief add the rest of the vector the tree
  /// only used if we haven't seen this state before
  /// @param current current node, we'll be adding children & descendants to this node 
  /// @param arrToAdd the array to add to the tree 
  /// @param indexToStartAt add from indexToStart at tot the end of arrToAdd
void ReachedTree::addRestOfVectorToTree(ReachedNode* current, vector<int> arrToAdd, int indexToStartAt) {
  ReachedNode* curr = current;
  // I guess we could do recursively but that would have higher runtime
  for (int i = indexToStartAt; i < (int)arrToAdd.size(); i++) {
    ReachedNode* toAdd = new ReachedNode(arrToAdd[i]);
    curr->children.push_back(toAdd);
    curr = toAdd;
  }
}