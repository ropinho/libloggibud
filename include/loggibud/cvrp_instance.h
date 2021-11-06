/**
 * Copyright 2021 <Ronaldd Pinho> <ronaldppinho@gmail.com>
 */
#ifndef LOGGIBUD_CVRP_INSTANCE_H_
#define LOGGIBUD_CVRP_INSTANCE_H_

#include <loggibud/delivery.h>
#include <loggibud/json/json_schema.h>
#include <loggibud/json/read.h>
#include <loggibud/json_dataclass_mixin.h>
#include <loggibud/point.h>
#include <rapidjson/document.h>

#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

namespace loggibud {
class CVRPInstance {
 public:
  string name;
  string region;
  Point origin;
  size_t vehicle_capacity;
  vector<Delivery> deliveries;

  static CVRPInstance from_file(string filename);
  static void to_file(string filename);
};
}  // namespace loggibud

#endif  // LOGGIBUD_CVRP_INSTANCE_H_
