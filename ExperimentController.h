#ifndef EXPERIMENT_CONTROLLER
#define EXPERIMENT_CONTROLLER

#include <iostream>
#include <string>
#include <vector>

#include "Agent.h"
#include "Loader.h"
// timing mechanism
// and other performance measures are going to go here
using namespace std;

class ExperimentController {
 public:
  static void runExperiment(string file, int heuristic);
};  // namespace std;

#endif