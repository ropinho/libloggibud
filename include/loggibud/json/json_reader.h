#ifndef LOGGIBUD_CXX_JSON_JSONREADER_H_
#define LOGGIBUD_CXX_JSON_JSONREADER_H_

#include <rapidjson/document.h>
using rapidjson::Value;

#include "../delivery.h"
#include "../point.h"

namespace loggiloggibud::json
{
    class JSONReader {
    public:
        static loggibud::Point read_point(Value &object) {
            double lng = object["lng"].GetDouble();
            double lat = object["lat"].GetDouble();
            return loggibud::Point{ lng, lat };
        }

        static loggibud::Delivery read_delivery(Value &object) {
            auto id = object["id"].GetString();
            auto point = loggibud::Point{
                object["point"].GetObject()["lng"].GetDouble(),
                object["point"].GetObject()["lat"].GetDouble()
            };
            size_t size = object["size"].GetUint64();
            return loggibud::Delivery{ id, point, size };
        }
    };

}

#endif
