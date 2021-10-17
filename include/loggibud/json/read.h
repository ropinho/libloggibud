#ifndef LOGGIBUD_CXX_JSON_JSONREADER_H_
#define LOGGIBUD_CXX_JSON_JSONREADER_H_

#include <rapidjson/document.h>
using rapidjson::Value;

#include "../delivery.h"
#include "../point.h"

namespace loggibud::json
{
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
    loggibud::Point read_point(Value &object);

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
     * @return a point with latitude and longitude
     */
    loggibud::Delivery read_delivery(Value &object);
}

#endif
