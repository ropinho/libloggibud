#ifndef LOGGIBUD_CXX_JSON_CONVERSORS_HPP_
#define LOGGIBUD_CXX_JSON_CONVERSORS_HPP_

#include <rapidjson/document.h>
using rapidjson::Value;

#include "../point.h"
#include "../delivery.h"

namespace loggibud
{
    /**
     * Convert a rapidjson::Value to a Point instance
     * @param obj the value parsed from JSON with rapidjson 
     * @returns a loggibud::Point */
    Point to_point(const Value &obj) {
        double lng = obj["lng"].GetDouble();
        double lat = obj["lat"].GetDouble();
        return Point{ lng, lat };
    }

    /**
     * Convert a rapidjson::Value to a Delivery instance
     * @param obj the value parsed from JSON with rapidjson 
     * @returns a loggibud::Delivery */
    Delivery to_delivery(const Value &obj) {
        auto id = obj["id"].GetString();
        auto point = loggibud::Point{
            obj["point"].GetObject()["lng"].GetDouble(),
            obj["point"].GetObject()["lat"].GetDouble()
        };
        size_t size = obj["size"].GetUint64();
        return loggibud::Delivery{ id, point, size };
    }
}

#endif
