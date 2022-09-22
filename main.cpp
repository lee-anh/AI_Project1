#include <iostream>
#include <string>
#include <vector>

#include "ExperimentController.h"

using namespace std;

int main() {
  ExperimentController::runExperiment("test3_6.txt", 1, "log/results3_1.txt");
  ExperimentController::runExperiment("test3_6.txt", 2, "log/results3_2.txt");
  ExperimentController::runExperiment("test3_6.txt", 3, "log/results3_3.txt");
  ExperimentController::runExperiment("test3_6.txt", 4, "log/results3_4.txt");
  return 0;
}