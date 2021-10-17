#ifndef LOGGIBUD_CXX_CVRPSOLUTION_H_
#define LOGGIBUD_CXX_CVRPSOLUTION_H_

#include <string>
#include <vector>
using std::string;
using std::vector;

#include "delivery.h"
#include "json_dataclass_mixin.h"

namespace loggibud
{
    class CVRPSolution : public JSONDataclassMixin<CVRPSolution> {
    public:
        string name;
        vector<Delivery> deliveries;

        CVRPSolution from_file(string filename) {
            return CVRPSolution();
        }

        void to_file(string filename) {}
    };
}

#endif
