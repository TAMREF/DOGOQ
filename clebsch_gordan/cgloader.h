#include "ndvector.h"
#include <map>
#include <string>
#include <tuple>
#include <type_traits>

namespace DOGOQ{
    template <typename T> class CGloader{
        static_assert(std::is_floating_point<T>::value, "Cgloader should be instantiazed by floating point type");
        //! TODO : Replace data type
        using d6 = std::tuple<int,int,int,int,int,int>;
        std::map<d6, T> dat;
    public:
        static const std::string fname;
        explicit CGloader(const std::string F=fname);
        ~CGloader();
        T operator() (d6 f) const;
        T operator() (double j1, double m1, double j2, double m2, double J, double M) const;
    };
}

#include "impl/cgloader-impl.h"
