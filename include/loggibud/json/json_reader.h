#ifndef LOGGIBUD_CXX_JSON_JSONREADER_H_
#define LOGGIBUD_CXX_JSON_JSONREADER_H_

#include <rapidjson/document.h>
using rapidjson::Value;

#include "../delivery.h"
#include "../point.h"

namespace bud::json
{
    class JSONReader {
    public:
        static bud::Point read_point(Value &object) {
            double lng = object["lng"].GetDouble();
            double lat = object["lat"].GetDouble();
            return bud::Point{ lng, lat };
        }

        static bud::Delivery read_delivery(Value &object) {
            auto id = object["id"].GetString();
            auto point = bud::Point{
                object["point"].GetObject()["lng"].GetDouble(),
                object["point"].GetObject()["lat"].GetDouble()
            };
            size_t size = object["size"].GetUint64();
            return bud::Delivery{ id, point, size };
        }
    };

}

#endif
