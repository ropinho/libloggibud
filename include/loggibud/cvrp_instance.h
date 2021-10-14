#ifndef LOGGIBUD_CPP_CVRPINSTANCE_H_
#define LOGGIBUD_CPP_CVRPINSTANCE_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "point.h"
#include "delivery.h"
#include "json_dataclass_mixin.h"

namespace bud
{
    class CVRPInstance : public JSONDataclassMixin<CVRPInstance> {
    public:
        string name;
        string region;
        Point origin;
        size_t vehicle_capacity;
        vector<Delivery> deliveries;

        CVRPInstance from_file(string filname) final {
            return CVRPInstance();
        }

        void to_file(string filename) final {}
    };
}

#endif
