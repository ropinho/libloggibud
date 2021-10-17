#ifndef LOGGIBUD_CXX_CVRPINSTANCE_H_
#define LOGGIBUD_CXX_CVRPINSTANCE_H_

#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include <rapidjson/document.h>

#include "point.h"
#include "delivery.h"
#include "json_dataclass_mixin.h"
#include "json/json_schema.h"
#include "json/read.h"

namespace loggibud
{
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
}

#endif
