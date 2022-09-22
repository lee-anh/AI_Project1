#ifndef REACHED_TREE
#define REACHED_TREE

#include <iostream>
#include <vector>

using namespace std;
class ReachedTree {
 public:
  ReachedTree();
  bool isReached(vector<int> puzzleArray);

 private:
  class ReachedNode {
   public:
    ReachedNode(int num) {
      this->num = num;
    }
    int num;
    vector<ReachedNode*> children;
  };
  ReachedNode* root;

  // add to reached?
  int hasChild(ReachedNode* current, int numberToCheck);
  void addRestOfVectorToTree(ReachedNode* current, vector<int> arrToAdd, int indexToStartAt);
};

#endif