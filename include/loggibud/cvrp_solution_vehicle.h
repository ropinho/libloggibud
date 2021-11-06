/**
 * Copyright 2021 <Ronaldd Pinho> <ronaldppinho@gmail.com>
 */
#ifndef LOGGIBUD_CVRP_SOLUTION_VEHICLE_H_
#define LOGGIBUD_CVRP_SOLUTION_VEHICLE_H_

#include <loggibud/delivery.h>
#include <loggibud/point.h>

#include <vector>

namespace loggibud {
class CVRPSolutionVehicle {
 public:
  Point origin;
  std::vector<Delivery> deliveries;

  std::vector<Point> circuit() {
    std::vector<Point> points;
    points.push_back(origin);
    for (Delivery &d : this->deliveries) {
      points.push_back(d.point);
    }
    points.push_back(origin);
    return points;
  }

  size_t occupation() {
    size_t sum = 0;
    for (Delivery &d : this->deliveries) {
      sum += d.size;
    }
    return sum;
  }
};
}  // namespace loggibud

#endif  // LOGGIBUD_CVRP_SOLUTION_VEHICLE_H_
