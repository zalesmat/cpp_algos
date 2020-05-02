#include <algorithm>

#include "convex_hull.h"

namespace mz {

std::vector<vec>& sort_unique(std::vector<vec>& v)
{
    auto customCompr = [](vec a, vec b) {
        if (a.x_ == b.x_)
            return a.y_ <= b.y_;
        return a.x_ < b.x_;
    };

    if (!std::is_sorted(v.begin(), v.end(), customCompr))
        std::sort(v.begin(), v.end(), customCompr);

    v.erase(std::unique(v.begin(), v.end()), v.end());

    return v;
}

}  // namespace mz

namespace mz {

std::vector<vec> convex_hull(std::vector<vec> const& vecSet)
{
    if (vecSet.size() > 3) {
        // std::vector<vec> hull{vecSet};
        // hull = sort_unique(hull);
    }
    return std::vector<vec>{vecSet};
}

}  // namespace mz