#include "../src/interviewproblems.h"
#include <gmock/gmock.h>

using namespace interviewproblems;

struct intTc{
    int inp;
    int exp;
};

TEST(numberofsteps, checkbasics){
    intTc tcs[] = {
        {0, 0},
        {1, 1},
        {-3, 0},
        {2, 2},
        {3, 3},
        {14, 6},
        {8, 4},
    };
    InterviewSolutions prob;

    for(intTc tc: tcs){
        EXPECT_EQ(tc.exp, prob.numberOfSteps(tc.inp));
    }
}

TEST(numberofsteps2, checkbasics){
intTc tcs[] = {
        {0, 0},
        {1, 1},
        {-3, 0},
        {2, 2},
        {3, 3},
        {14, 6},
        {8, 4},
    };
    InterviewSolutions prob;

    for(intTc tc: tcs){
        EXPECT_EQ(tc.exp, prob.numberOfStepsTwo(tc.inp));
    }
}

struct intVecTc{
    std::vector<int> inp;
    std::vector<int> exp;
};

TEST(RLElist, checkbasics){
    intVecTc tcs[] = {
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
    for (intVecTc tc: tcs){
        EXPECT_THAT(tc.exp, testing::ContainerEq(prob.decompressRLElist(tc.inp)));
    }
    
}

TEST(SmallerNumbers, basicTests){
    intVecTc tcs[] = {
        {
            {8,1,2,2,3},
            {4,0,1,1,3},
        },
        {
            {0},
            {0},
        },
        {
            {6,5,4,8},
            {2,1,0,3},
        },
        {
            {3,3},
            {0,0},
        },
    };
}