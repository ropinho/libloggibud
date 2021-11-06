/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_DELIVERY_H_
#define LOGGIBUD_DELIVERY_H_

#include <loggibud/point.h>
#include <string>

namespace loggibud {
struct Delivery {
  std::string id;
  Point point;
  size_t size;
};
}  // namespace loggibud

#endif  // LOGGIBUD_DELIVERY_H_
