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

namespace bud
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

bud::CVRPInstance bud::CVRPInstance::from_file(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        string filecontent = string(
            std::istreambuf_iterator<char>(),
            std::istreambuf_iterator<char>(file)
        );
        file.close();

        rapidjson::Document d;
        d.Parse(filecontent.c_str());

        // TODO: Finalize CVRPInstance JSON parsing.
    }
}

#endif
