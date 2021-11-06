/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_JSON_READ_H_
#define LOGGIBUD_JSON_READ_H_

#include <rapidjson/document.h>
using rapidjson::Value;

#include "../delivery.h"
#include "../point.h"

namespace loggibud::json {
/**
 * @brief Reads a Point from a value defined by a json object
 *
 * From a JSON value from RapidJSON (rapidjson::Value), this function
 * generate a loggibud::Point, the objet format is not pre-validated and
 * should have two numeric fields: lng and lat.
 *
 * @param object An instance of rapidjson::Value
 *
 * @return a point with latitude and longitude
 */
loggibud::Point read_point(const Value &object);

/**
 * @brief Reads a Delivery from a value defined by a json object
 *
 * From a JSON value from RapidJSON (rapidjson::Value), this function
 * generate a loggibud::Delivery, the objet format is not pre-validated and
 * should have three fields: "size" which is a numeric value, "point" that
 * should have two fields (lng & lat) and "id" that should be a string.
 *
 * @param object An instance of rapidjson::Value
 *
 * @return a delivery composed by a Point , Id and Size (integer)
 */
loggibud::Delivery read_delivery(const Value &object);
}  // namespace loggibud::json

#endif  // LOGGIBUD_JSON_READ_H_
