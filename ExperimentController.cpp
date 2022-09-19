#include "ExperimentController.h"

void ExperimentController::runExperiment(string file, int heuristic) {
  Loader* l = new Loader(file);
  int edgeSize = l->getEdgeSize();
  int count = 0;
  while (l->hasNextProblem()) {
    cout << "Puzzle " << count << " *********************" << endl;
    Puzzle* puzzle = new Puzzle(l->getProblem(), edgeSize);

    // should the heuristicEstimate start at 0 as well?
    Node* root = new Node(puzzle, NULL, 0, 0, 0, 0);
    Agent* agent = new Agent(root, heuristic);
    agent->AStarSearch();
    count++;
  }

  // got to get the problem, make it a node and feed it to the Agent
}
