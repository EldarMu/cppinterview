#include "../src/interviewproblems.h"
#include <gtest/gtest.h>

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