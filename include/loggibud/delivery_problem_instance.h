/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_DELIVERY_PROBLEM_INSTANCE_H_
#define LOGGIBUD_DELIVERY_PROBLEM_INSTANCE_H_

#include <loggibud/delivery.h>
#include <loggibud/json_dataclass_mixin.h>

#include <string>
#include <vector>
using std::string;
using std::vector;

namespace loggibud {
class DeliveryProblemInstance {
 public:
  string name;
  string region;
  size_t max_hubs;
  size_t vehicle_capacity;
  vector<Delivery> deliveries;
};
}  // namespace loggibud

#endif  // LOGGIBUD_DELIVERY_PROBLEM_INSTANCE_H_
