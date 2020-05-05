#include <algorithm>
#include <list>
#include <stdexcept>

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

bool right_turn(std::list<vec> const& v)
{
    if (v.size() > 2) {
        auto c = v.rbegin();
        auto b = std::next(c);
        auto a = std::next(b);

        vec v1 = *b - *a;
        vec v2 = *c - *b;

        return (v1.x_ * v2.y_ - v1.y_ * v2.x_) < 0;
    }
    throw std::runtime_error("right_turn: list size < 3");
}

std::list<vec> compute_hull(std::vector<vec> const& v)
{
    if (v.size() > 2) {
        std::list<vec> hull{v[0], v[1]};

        for (size_t i = hull.size(); i < v.size(); ++i) {
            hull.push_back(v[i]);
            while (hull.size() > 2 && !right_turn(hull)) {
                auto lastButOne = std::prev(std::prev(hull.end()));
                hull.erase(lastButOne);
            }
        }
        return hull;
    }
    throw std::runtime_error("compute_hull: vector size < 3");
}

}  // namespace mz

namespace mz {

std::vector<vec> convex_hull(std::vector<vec> const& vecSet)
{
    if (vecSet.size() > 3) {
        std::vector<vec> vecUniqueSorted{vecSet};
        vecUniqueSorted = sort_unique(vecUniqueSorted);

        auto upperHull = compute_hull(vecUniqueSorted);

        std::reverse(vecUniqueSorted.begin(), vecUniqueSorted.end());
        auto lowerHull = compute_hull(vecUniqueSorted);

        for (auto it = std::next(lowerHull.begin()); it != std::prev(lowerHull.end()); ++it)
            upperHull.push_back(*it);

        return std::vector<vec>{upperHull.begin(), upperHull.end()};
    }
    return std::vector<vec>{vecSet};
}

}  // namespace mz