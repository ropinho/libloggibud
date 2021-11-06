/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#include "../include/loggibud/json/read.h"

loggibud::Point loggibud::json::read_point(const rapidjson::Value &object) {
  double lng = object["lng"].GetDouble();
  double lat = object["lat"].GetDouble();
  return loggibud::Point{lng, lat};
}

loggibud::Delivery loggibud::json::read_delivery(
    const rapidjson::Value &object) {
  auto id = object["id"].GetString();
  auto point = loggibud::Point{object["point"].GetObject()["lng"].GetDouble(),
                               object["point"].GetObject()["lat"].GetDouble()};
  size_t size = object["size"].GetUint64();
  return loggibud::Delivery{id, point, size};
}
