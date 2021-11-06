/**
 * Copyright 2021 <Ronaldd Pinho>
 */
#ifndef LOGGIBUD_JSON_DATACLASS_MIXIN_H_
#define LOGGIBUD_JSON_DATACLASS_MIXIN_H_

#include <string>

namespace loggibud {
template <class Dataclass>
class JSONDataclassMixin {
 public:
  virtual Dataclass from_file(std::string filename) = 0;
  virtual void to_file(std::string filename) = 0;
};
}  // namespace loggibud

#endif  // LOGGIBUD_JSON_DATACLASS_MIXIN_H_
