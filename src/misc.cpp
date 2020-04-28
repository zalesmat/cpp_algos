#include <stdexcept>
#include "misc.h"

namespace mz {

int greatest_common_divisor(int a, int b)
{
    if (a != 0) {
        if (b == 0)
            return a;

        return greatest_common_divisor(b, std::abs(a) % std::abs(b));
    }

    throw std::runtime_error("greatest_common_divisor: can't divide by 0 (first arg)\n");
}

}  // namespace mz