#include <iostream>
#include <string>
#include <vector>

#include "ExperimentController.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }
  int arg = stoi(argv[1]);
  switch (arg) {
    case 0:
      // tests
      ExperimentController::runTests();
      ExperimentController::testHeuristic3("test3_6.txt");

    case 2:
      // three puzzle
      ExperimentController::runAllExperiments("every_three_puzzle.txt", "log/results2", "log/averages/results2.txt");
      break;
    case 3:
      // eight puzzle
      ExperimentController::runAllExperiments("test3_6.txt", "log/results3_6", "log/averages/results3_6.txt");
      ExperimentController::runAllExperiments("test3_7.txt", "log/results3_7", "log/averages/results3_7.txt");
      ExperimentController::runAllExperiments("test3_8.txt", "log/results3_8", "log/averages/results3_8.txt");

      break;
    case 4:
      // fifteen puzzle
      // These take a long time to run, so comment out ones you don't need
      ExperimentController::runAllExperiments("test4_10.txt", "log/results4_10", "log/averages/results4_10.txt");
      ExperimentController::runAllExperiments("test4_11.txt", "log/results4_11", "log/averages/results4_11.txt");
      // ExperimentController::runAllExperiments("test4_12.txt", "log/results4_12", "log/averages/results4_12.txt");
      // ExperimentController::runAllExperiments("test4_13.txt", "log/results4_13", "log/averages/results4_13.txt");
      //  ExperimentController::runAllExperiments("test4_15.txt", "log/results4_15", "log/averages/results4_15.txt");

      break;

    default:
      return 0;
  }

  return 0;
}