#ifndef LOGGIBUD_CPP_DELIVERY_H_
#define LOGGIBUD_CPP_DELIVERY_H_

#include <string>
using std::string;

#include "point.h"

namespace bud
{
    struct Delivery {
        string id;
        Point point;
        size_t size;
    };
}

#endif
