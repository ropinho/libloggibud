#ifndef LOGGIBUD_CPP_JSONDATACLASSMIXIN_H_
#define LOGGIBUD_CPP_JSONDATACLASSMIXIN_H_

#include <string>

namespace bud
{
    template <class Dataclass>
    class JSONDataclassMixin {
    public:
        virtual Dataclass from_file(std::string filename) = 0;
        virtual void to_file(std::string filename) = 0;
    };
}

#endif
