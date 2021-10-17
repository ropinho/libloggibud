#ifndef LOGGIBUD_CXX_DELIVERYPROBLEMINSTANCE_H_
#define LOGGIBUD_CXX_DELIVERYPROBLEMINSTANCE_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "delivery.h"
#include "json_dataclass_mixin.h"

namespace loggibud
{
    class DeliveryProblemInstance {
    public:
        string name;
        string region;
        size_t max_hubs;
        size_t vehicle_capacity;
        vector<Delivery> deliveries;
    };
}

#endif
