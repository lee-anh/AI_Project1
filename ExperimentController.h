#ifndef EXPERIMENT_CONTROLLER
#define EXPERIMENT_CONTROLLER

#include <iostream>
#include <string>
#include <vector>

#include "Agent.h"
#include "Loader.h"

using namespace std;

class ExperimentController {
 public:
  static void runExperiment(string inputFile, int heuristic, string outputFile);
};

#endif