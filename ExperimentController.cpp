#include "ExperimentController.h"

/// @brief run a configuration for all the heuristics
/// calls runExperiment for each of the heuristics
/// @param inputFile file of problems
/// @param baseOutputFileName output file name for each heuristic
/// @param sumOutputFile output file for averages
void ExperimentController::runAllExperiments(string inputFile, string baseOutputFileName, string sumOutputFile) {
  runExperiment(inputFile, 1, baseOutputFileName + "_1.txt", sumOutputFile);
  runExperiment(inputFile, 2, baseOutputFileName + "_2.txt", sumOutputFile);
  runExperiment(inputFile, 3, baseOutputFileName + "_3.txt", sumOutputFile);
  runExperiment(inputFile, 4, baseOutputFileName + "_4.txt", sumOutputFile);
}

/// @brief run a configuration for a specific heuristics
/// load in problems, maintain running averages, output averages to output file
/// @param inputFile file of problems
/// @param heuristic to use
/// @param baseOutputFileName output file name for each heuristic
/// @param sumOutputFile output file for averages

void ExperimentController::runExperiment(string inputFile, int heuristic, string outputFile, string sumOutputFile) {
  // clear the file
  ofstream myFile;
  myFile.open(outputFile);
  myFile << "";
  myFile.close();

  Loader* l = new Loader(inputFile);
  int edgeSize = l->getEdgeSize();

  // maintain averages to prevent overflow
  float averageTimeToSolve = 0;
  float averageBranchingFactor = 0;
  float averageFrontierSize = 0;
  float averageNumberOfNodes = 0;
  float averageParentNodes = 0;
  float averageSolutionDepth = 0;
  int numProbs = 1;
  ofstream sumFile;
  sumFile.open(sumOutputFile, ios_base::app);

  while (l->hasNextProblem()) {
    Puzzle* puzzle = new Puzzle(l->getProblem(), edgeSize);
    Node* root = new Node(puzzle, NULL, 0, 0, 0, 0);
    Agent* agent = new Agent(root, heuristic, outputFile);
    agent->AStarSearch();
    averageTimeToSolve = ((numProbs - 1) / (numProbs * 1.0)) * averageTimeToSolve + (1.0 / numProbs) * agent->getTimeToSolve();
    averageBranchingFactor = ((numProbs - 1) / (numProbs * 1.0)) * averageBranchingFactor + (1.0 / numProbs) * agent->getAverageBranchingFactor();
    averageFrontierSize = ((numProbs - 1) / (numProbs * 1.0)) * averageFrontierSize + (1.0 / numProbs) * agent->getAverageFrontierSize();
    averageNumberOfNodes = ((numProbs - 1) / (numProbs * 1.0)) * averageNumberOfNodes + (1.0 / numProbs) * agent->getTotalNumberOfNodes();
    averageParentNodes = ((numProbs - 1) / (numProbs * 1.0)) * averageParentNodes + (1.0 / numProbs) * agent->getTotalNumberOfParentNodes();
    averageSolutionDepth = ((numProbs - 1) / (numProbs * 1.0)) * averageSolutionDepth + (1.0 / numProbs) * agent->getDeepestDepth();
    numProbs++;
  }

  sumFile << heuristic << "\t" << averageTimeToSolve << "\t" << averageBranchingFactor << "\t"
          << averageFrontierSize << "\t" << averageNumberOfNodes << "\t" << averageParentNodes << "\t"
          << averageSolutionDepth << "\t" << pow(averageNumberOfNodes, 1 / averageSolutionDepth) << endl;
  sumFile.close();
}

/// @brief run some tests to ensure the program is working as intended
/// test heuristics for an example problem
void ExperimentController::runTests() {
  Loader* l = new Loader("testHeuristics.txt");
  int edgeSize = l->getEdgeSize();
  Puzzle* puzzle = new Puzzle(l->getProblem(), edgeSize);
  ofstream myFile;
  myFile.open("./log/testResults.txt");
  myFile << "MisplacedTiles :" << Heuristic::calculateHeuristic(puzzle, 1) << " == 8?" << endl;
  myFile << "ManhattanDistance: " << Heuristic::calculateHeuristic(puzzle, 2) << " == 18?" << endl;
  myFile << "Swaps from maxSort: " << Heuristic::calculateHeuristic(puzzle, 3) << "== 8?" << endl;
  myFile << "GeometricDistance: " << Heuristic::calculateHeuristic(puzzle, 4) << " ~ 14.5366?" << endl;
  myFile.close();
}

/// @brief test if h3 is less than or equal to h1
/// @param testFile input file
void ExperimentController::testHeuristic3(string testFile) {
  Loader* l = new Loader(testFile);
  int edgeSize = l->getEdgeSize();
  ofstream myFile;
  myFile.open("./log/test_h1h3.txt");
  while (l->hasNextProblem()) {
    Puzzle* puzzle = new Puzzle(l->getProblem(), edgeSize);
    myFile << Heuristic::calculateHeuristic(puzzle, 1) << " == " << Heuristic::calculateHeuristic(puzzle, 3) << "?" << endl;
  }
}