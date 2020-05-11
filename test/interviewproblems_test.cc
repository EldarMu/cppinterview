#include "../src/interviewproblems.h"
#include <gmock/gmock.h>

using namespace interviewproblems;

struct nos_tc{
    int inp;
    int exp;
};

TEST(numberofsteps, checkbasics){
    nos_tc tcs[] = {
        {0, 0},
        {1, 1},
        {-3, 0},
        {2, 2},
        {3, 3},
        {14, 6},
        {8, 4},
    };
    InterviewSolutions prob;

    for(nos_tc tc: tcs){
        EXPECT_EQ(tc.exp, prob.numberOfSteps(tc.inp));
    }
}

TEST(numberofsteps2, checkbasics){
nos_tc tcs[] = {
        {0, 0},
        {1, 1},
        {-3, 0},
        {2, 2},
        {3, 3},
        {14, 6},
        {8, 4},
    };
    InterviewSolutions prob;

    for(nos_tc tc: tcs){
        EXPECT_EQ(tc.exp, prob.numberOfStepsTwo(tc.inp));
    }
}

struct rle_tc{
    std::vector<int> inp;
    std::vector<int> exp;
};

TEST(RLElist, checkbasics){
    rle_tc tcs[] = {
        {
            {},
            {},
        },
        {
            {0,1},
            {},
        },
        {
            {-1, 1, 2, 2},
            {2,2},
        },
        {
            {1,1},
            {1},
        },
        {
            {3,12934, 1, 33333, 5, 1},
            {12934, 12934, 12934, 33333, 1, 1, 1, 1, 1},
        },
    };

    InterviewSolutions prob;
    for (rle_tc tc: tcs){
        EXPECT_THAT(tc.exp, testing::ContainerEq(prob.decompressRLElist(tc.inp)));
    }
    
}