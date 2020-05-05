#ifndef MZ_CONVEX_HULL_
#define MZ_CONVEX_HULL_

#include <vector>

namespace mz {

struct vec
{
    constexpr vec() = default;
    constexpr vec(int x, int y) noexcept : x_(x), y_(y) {}
    int x_ = 0;
    int y_ = 0;
};

constexpr inline bool operator==(vec const& lhs, vec const& rhs) noexcept
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

constexpr inline vec operator-(vec const& lhs, vec const& rhs)
{
    return vec{lhs.x_ - rhs.x_, lhs.y_ - rhs.y_};
}

std::vector<vec> convex_hull(std::vector<vec> const& vecSet);

}

#endif  // !MZ_CONVEX_HULL_