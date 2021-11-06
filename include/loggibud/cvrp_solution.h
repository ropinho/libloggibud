/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_CVRP_SOLUTION_H_
#define LOGGIBUD_CVRP_SOLUTION_H_

#include <loggibud/cvrp_solution_vehicle.h>
#include <loggibud/delivery.h>

#include <string>
#include <vector>

namespace loggibud {
class CVRPSolution {
 public:
  std::string name;
  std::vector<CVRPSolutionVehicle> vehicles;
};
}  // namespace loggibud

#endif  // LOGGIBUD_CVRP_SOLUTION_H_
