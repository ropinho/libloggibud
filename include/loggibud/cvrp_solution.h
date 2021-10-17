#ifndef LOGGIBUD_CXX_CVRPSOLUTION_H_
#define LOGGIBUD_CXX_CVRPSOLUTION_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "delivery.h"
#include "cvrp_solution_vehicle.h"

namespace loggibud
{
    class CVRPSolution {
    public:
        string name;
        vector<CVRPSolutionVehicle> vehicles;
    };
}

#endif
