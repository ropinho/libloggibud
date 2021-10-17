#ifndef LOGGIBUD_CXX_JSONDATACLASSMIXIN_H_
#define LOGGIBUD_CXX_JSONDATACLASSMIXIN_H_

#include <string>

namespace loggibud
{
    template <class Dataclass>
    class JSONDataclassMixin {
    public:
        virtual Dataclass from_file(std::string filename) = 0;
        virtual void to_file(std::string filename) = 0;
    };
}

#endif
