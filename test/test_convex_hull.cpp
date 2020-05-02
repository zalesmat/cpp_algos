#include <gtest/gtest.h>
#include "convex_hull.h"

using namespace mz;

namespace mz {

std::vector<vec>& sort_unique(std::vector<vec>& v);
}

TEST(VEC, EqualsToOperator)
{
    const vec vecA{1, 2};
    const vec vecB{2, 1};
    const vec vecC{1, 2};

    EXPECT_FALSE(vecA == vecB);
    EXPECT_TRUE(vecA == vecC);
}

TEST(SortUnique, HandlesEmptyVector)
{
    std::vector<vec> cvx;
    cvx = sort_unique(cvx);

    EXPECT_TRUE(cvx.empty());
}

TEST(SortUnique, HandlesOneElemVector)
{
    std::vector<vec> cvx(1);
    const auto cvxCopy{cvx};

    cvx = sort_unique(cvx);
    EXPECT_EQ(cvx, cvxCopy);
}

TEST(SortUnique, HandlesAlreadySortedVectorUnique)
{
    std::vector<vec> cvx{{-3, 1}, {-2, -1}, {-2, 0}, {1, 4}};
    auto cvxCopy{cvx};
    cvx = sort_unique(cvx);

    EXPECT_EQ(cvx, cvxCopy);
}

TEST(SortUnique, HandlesUnsortedVector)
{
    std::vector<vec> cvx{{0, 0}, {-1, 3}, {3, 1}, {1, 2}, {-4, 2}, {-1, 2}};
    auto cvxCopy{cvx};
    std::vector<vec> cvxSorted{{-4, 2}, {-1, 2}, {-1, 3}, {0, 0}, {1, 2}, {3, 1}};

    cvx = sort_unique(cvx);
    EXPECT_NE(cvx, cvxCopy);
    EXPECT_EQ(cvx, cvxSorted);
}

TEST(SortUnique, HandlesAlreadySortedVectorNotUnique)
{
    std::vector<vec> cvx{{-3, 1}, {-3, 1}, {-2, -1}, {-2, 0}, {1, 4}, {1, 4}};
    auto cvxCopy{cvx};
    std::vector<vec> cvxSorted{{-3, 1}, {-2, -1}, {-2, 0}, {1, 4}};

    cvx = sort_unique(cvx);
    EXPECT_NE(cvx, cvxCopy);
    EXPECT_EQ(cvx, cvxSorted);
}

TEST(SortUnique, HandlesUnsortedVectorNotUnique)
{
    std::vector<vec> cvx{{0, 0}, {-1, 3}, {3, 1}, {3, 1}, {1, 2}, {-4, 2}, {-4, 2}, {-1, 2}};
    std::vector<vec> cvxCopy{cvx};
    std::vector<vec> cvxSorted{{-4, 2}, {-1, 2}, {-1, 3}, {0, 0}, {1, 2}, {3, 1}};

    cvx = sort_unique(cvx);
    EXPECT_NE(cvx, cvxCopy);
    EXPECT_EQ(cvx, cvxSorted);
}

TEST(ConvexHull, CanHandleVectorSizeLT4)
{
    const std::vector<vec> cvx_sz0;
    const std::vector<vec> cvx_sz1(1);
    const std::vector<vec> cvx_sz2(2);
    const std::vector<vec> cvx_sz3{{1, 0}, {-1, 0}, {0, 1}};

    auto cvxResult = convex_hull(cvx_sz0);
    EXPECT_EQ(cvx_sz0, cvxResult);

    cvxResult = convex_hull(cvx_sz1);
    EXPECT_EQ(cvx_sz1, cvxResult);

    cvxResult = convex_hull(cvx_sz2);
    EXPECT_EQ(cvx_sz2, cvxResult);

    cvxResult = convex_hull(cvx_sz3);
    EXPECT_EQ(cvx_sz3, cvxResult);
}
