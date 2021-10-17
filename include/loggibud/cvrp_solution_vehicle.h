#ifndef LOGGIBUD_CXX_CVRPSOLUTIONVEHICLE_H_
#define LOGGIBUD_CXX_CVRPSOLUTIONVEHICLE_H_

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "point.h"
#include "delivery.h"

namespace loggibud
{
    class CVRPSolutionVehicle {
    public:
        Point origin;
        vector<Delivery> deliveries;

        vector<Point> circuit() {
            vector<Point> points;
            points.push_back(origin);
            for (Delivery &d : this->deliveries) {
                points.push_back(d.point);
            }
            points.push_back(origin);
            return points;
        }

        size_t occupation() {
            size_t sum = 0;
            for (Delivery &d : this->deliveries) {
                sum += d.size;
            }
            return sum;
        }
    };
}

#endif
