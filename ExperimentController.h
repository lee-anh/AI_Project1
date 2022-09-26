#ifndef EXPERIMENT_CONTROLLER
#define EXPERIMENT_CONTROLLER

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Agent.h"
#include "Loader.h"

using namespace std;

/// @brief static class that controls the configuration of experiments
class ExperimentController {
 public:

  /// @brief run a configuration for all the heuristics 
  /// @param inputFile file of problems 
  /// @param baseOutputFileName output file name for each heuristic 
  /// @param sumOutputFile output file for averages 
  static void runAllExperiments(string inputFile, string baseOutputFileName, string sumOutputFile);

  /// @brief run a configuration for a specific heuristics
  /// @param inputFile file of problems 
  /// @param heuristic to use 
  /// @param baseOutputFileName output file name for each heuristic 
  /// @param sumOutputFile output file for averages 
  static void runExperiment(string inputFile, int heuristic, string outputFile, string sumOutputFile);


  /// @brief run some tests to ensure the program is working as intended 
  static void runTests();

  /// @brief test if h3 is less than or equal to h1 
  /// @param testFile 
  static void testHeuristic3(string testFile);
};

#endif