#ifndef REACHED_TREE
#define REACHED_TREE

#include <iostream>
#include <vector>

using namespace std;
/// @brief Dictionary to ensure states aren't repeated
/// constructs a tree where each depth corresponds to index + 1
class ReachedTree {
 public:
  /// @brief constructor, initialize the dictionary with a root
  ReachedTree();

  /// @brief check to see if the puzzleArray has been reached before
  /// @param puzzleArray
  /// @return true if the state has been reached before, false if not
  bool isReached(vector<int> puzzleArray);

 private:
  /// @brief internal class, each node just has a number and children (of next numbers)
  class ReachedNode {
   public:
    ReachedNode(int num) {
      this->num = num;
    }
    int num;
    vector<ReachedNode*> children;
  };
  ReachedNode* root;

  /// @brief check to see if a certain node has a child with a certain number
  /// @param current node to check children of
  /// @param numberToCheck number we're looking for
  /// @return the index of the child, -1 if there is no child
  int hasChild(ReachedNode* current, int numberToCheck);

  /// @brief add the rest of the vector the tree
  /// @param current current node, we'll be adding children & descendants to this node
  /// @param arrToAdd the array to add to the tree
  /// @param indexToStartAt add from indexToStart at tot the end of arrToAdd
  void addRestOfVectorToTree(ReachedNode* current, vector<int> arrToAdd, int indexToStartAt);
};

#endif