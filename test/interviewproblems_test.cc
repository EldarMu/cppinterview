#include "../src/interviewproblems.h"
#include "../src/testhelpers.h"
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
        EXPECT_EQ(prob.numberOfSteps(tc.inp), tc.exp);
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
        EXPECT_EQ(prob.numberOfStepsTwo(tc.inp), tc.exp);
    }
}

struct intVecTc{
    vector<int> inp;
    vector<int> exp;
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
        EXPECT_THAT(prob.decompressRLElist(tc.inp), testing::ContainerEq(tc.exp));
    }
    
}

TEST(SmallerNumbersSort, basicTests){
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
    InterviewSolutions prob;
    for(intVecTc tc: tcs){
        EXPECT_THAT(prob.smallerNumbersThanCurrentSort(tc.inp), testing::ContainerEq(tc.exp));
    }
}

TEST(SmallerNumbersHeap, basicTests){
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
    InterviewSolutions prob;
    for(intVecTc tc: tcs){
        EXPECT_THAT(prob.smallerNumbersThanCurrentHeap(tc.inp), testing::ContainerEq(tc.exp));
    }
}

TEST(SmallerNumbersCount, basicTests){
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
    InterviewSolutions prob;
    for(intVecTc tc: tcs){
        EXPECT_THAT(prob.smallerNumbersThanCurrentCountSort(tc.inp), testing::ContainerEq(tc.exp));
    }
}

TEST(GetTargetCopyDFS, basicTests){
    vector<vector<int>> inputs = {
        //using INT_MIN as standin for nullptr
        {7,4,3,INT_MIN,INT_MIN,6,19},
        {7},
        {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,INT_MIN,3},
    };

    for(vector<int> inp: inputs){
        TreeNode* orighead = genTreeFromVec(inp);
        TreeNode* copyhead = genTreeFromVec(inp);
        TreeNode* target = getRandomNode(orighead);
        InterviewSolutions prob;
        TreeNode* result = prob.getTargetCopyRecurs(orighead, copyhead, target);
        EXPECT_EQ(result->val, target->val);
    }
}

TEST(GetTargetCopyBFS, basicTests){
    vector<vector<int>> inputs = {
        // using INT_MIN as standin for nullptr
        {7,4,3,INT_MIN,INT_MIN,6,19},
        {7},
        {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
        {1,2,3,4,5,6,7,8,9,10},
        {1,2,INT_MIN,3},
    };

    for(vector<int> inp: inputs){
        TreeNode* orighead = genTreeFromVec(inp);
        TreeNode* copyhead = genTreeFromVec(inp);
        TreeNode* target = getRandomNode(orighead);
        InterviewSolutions prob;
        TreeNode* result = prob.getTargetCopyBFS(orighead, copyhead, target);
        EXPECT_EQ(result->val, target->val);
    }
}
