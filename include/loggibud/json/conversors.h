/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_JSON_CONVERSORS_H_
#define LOGGIBUD_JSON_CONVERSORS_H_

#include <rapidjson/document.h>
using rapidjson::Value;

#include <loggibud/delivery.h>
#include <loggibud/point.h>

namespace loggibud {
/**
 * Convert a rapidjson::Value to a Point instance
 * @param obj the value parsed from JSON with rapidjson
 * @returns a loggibud::Point */
Point to_point(const Value &obj) {
  double lng = obj["lng"].GetDouble();
  double lat = obj["lat"].GetDouble();
  return Point{lng, lat};
}

/**
 * Convert a rapidjson::Value to a Delivery instance
 * @param obj the value parsed from JSON with rapidjson
 * @returns a loggibud::Delivery */
Delivery to_delivery(const Value &obj) {
  auto id = obj["id"].GetString();
  auto point = loggibud::Point{obj["point"].GetObject()["lng"].GetDouble(),
                               obj["point"].GetObject()["lat"].GetDouble()};
  size_t size = obj["size"].GetUint64();
  return loggibud::Delivery{id, point, size};
}
}  // namespace loggibud

#endif  // LOGGIBUD_JSON_CONVERSORS_H_
