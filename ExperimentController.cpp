#include "ExperimentController.h"

void ExperimentController::runExperiment(string inputFile, int heuristic, string outputFile) {
  Loader* l = new Loader(inputFile);
  int edgeSize = l->getEdgeSize();
  int count = 0;
  while (l->hasNextProblem()) {
    Puzzle* puzzle = new Puzzle(l->getProblem(), edgeSize);

    // should the heuristicEstimate start at 0 as well?
    Node* root = new Node(puzzle, NULL, 0, 0, 0, 0);
    Agent* agent = new Agent(root, heuristic, outputFile);
    agent->AStarSearch();
    count++;
  }
}
