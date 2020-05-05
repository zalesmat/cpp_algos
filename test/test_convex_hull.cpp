#include <gtest/gtest.h>
#include <algorithm>
#include <list>
#include "convex_hull.h"

using namespace mz;

namespace mz {

std::vector<vec>& sort_unique(std::vector<vec>& v);
bool right_turn(std::list<vec> const& l);
std::list<vec> compute_hull(std::vector<vec> const& v);

}  // namespace mz

TEST(VEC, EqualsToOperator)
{
    const vec vecA{1, 2};
    const vec vecB{2, 1};
    const vec vecC{1, 2};

    EXPECT_FALSE(vecA == vecB);
    EXPECT_TRUE(vecA == vecC);
}

TEST(VEC, SubtractionOperator)
{
    const vec vecA{-4, 1};
    const vec vecB{-1, 1};
    const vec resultAB{-3, 0};
    const vec resultBA{3, 0};

    EXPECT_EQ(vecA - vecB, resultAB);
    EXPECT_EQ(vecB - vecA, resultBA);
}

TEST(RightTurn, ThrowsIfListSizeLT3)
{
    std::list<vec> list_sz0;
    std::list<vec> list_sz1(1);
    std::list<vec> list_sz2(2);

    EXPECT_THROW(right_turn(list_sz0), std::runtime_error);
    EXPECT_THROW(right_turn(list_sz1), std::runtime_error);
    EXPECT_THROW(right_turn(list_sz2), std::runtime_error);
}

TEST(RightTurn, HandlesListSizeGT2WithNoRightTurn)
{
    const std::list<vec> list_sz3{{-4, 1}, {-3, 0}, {-1, 1}};
    const std::list<vec> list_sz4{{-4, 1}, {-3, -1}, {-3, 0}, {-3, 2}};

    EXPECT_FALSE(right_turn(list_sz3));
    EXPECT_FALSE(right_turn(list_sz4));
}

TEST(RightTurn, HandlesListSizeGT2WithRightTurn)
{
    const std::list<vec> list_sz3{{-3, -1}, {-3, 0}, {-2, 0}};
    const std::list<vec> list_sz4{{-4, 1}, {-3, -1}, {-3, 0}, {-1, 1}};

    EXPECT_TRUE(right_turn(list_sz3));
    EXPECT_TRUE(right_turn(list_sz4));
}

TEST(ComputeHull, HandlesVectorSizeLT3)
{
    std::vector<vec> vec_sz0;
    std::vector<vec> vec_sz1(1);
    std::vector<vec> vec_sz2(2);

    EXPECT_THROW(compute_hull(vec_sz0), std::runtime_error);
    EXPECT_THROW(compute_hull(vec_sz1), std::runtime_error);
    EXPECT_THROW(compute_hull(vec_sz2), std::runtime_error);
}

TEST(ComputeHull, HandlesVectorSizeGT2)
{
    std::vector<vec> vec_sz3{{-4, 1}, {-3, 0}, {-3, 2}};
    const std::list<vec> expectedResult_sz3{{-4, 1}, {-3, 2}};
    std::vector<vec> vec_sz6{{-4, 1}, {-3, -1}, {-3, 0}, {-3, 2}, {-2, 0}, {-1, 1}};
    const std::list<vec> expectedResult_sz6{{-4, 1}, {-3, 2}, {-1, 1}};

    EXPECT_EQ(compute_hull(vec_sz3), expectedResult_sz3);
    EXPECT_EQ(compute_hull(vec_sz6), expectedResult_sz6);
}

TEST(ComputeHull, HandlesReversedVector)
{
    std::vector<vec> vec_sz3{{-4, 1}, {-3, 0}, {-3, 2}};
    const std::list<vec> expectedResult_sz3{{-3, 2}, {-3, 0}, {-4, 1}};
    std::reverse(vec_sz3.begin(), vec_sz3.end());

    std::vector<vec> vec_sz6{{-4, 1}, {-3, -1}, {-3, 0}, {-3, 2}, {-2, 0}, {-1, 1}};
    const std::list<vec> expectedResult_sz6{{-1, 1}, {-3, -1}, {-4, 1}};
    std::reverse(vec_sz6.begin(), vec_sz6.end());

    EXPECT_EQ(compute_hull(vec_sz3), expectedResult_sz3);
    EXPECT_EQ(compute_hull(vec_sz6), expectedResult_sz6);
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

TEST(ConvexHull, CanHandleVectorSizeGT3)
{
    const std::vector<vec> cvx_sz4{{-4, 1}, {-1, 1}, {-3, -1}, {-3, 0}};
    const std::vector<vec> expectedHull_sz4{{-4, 1}, {-1, 1}, {-3, -1}};

    const std::vector<vec> cvx_sz9{{0, 0}, {-1, -1}, {1, 1},  {-1, 1}, {1, -1},
                                   {1, 0}, {-1, 0},  {0, -1}, {0, 1}};
    const std::vector<vec> expectedHull_sz9{{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};

    auto cvxResult = convex_hull(cvx_sz4);
    EXPECT_EQ(cvxResult, expectedHull_sz4);

    cvxResult = convex_hull(cvx_sz9);
    EXPECT_EQ(cvxResult, expectedHull_sz9);
}
