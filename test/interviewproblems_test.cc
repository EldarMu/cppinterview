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
    InterviewSolutions prob;
    for(vector<int> inp: inputs){
        TreeNode* orighead = genTreeFromVec(inp);
        TreeNode* copyhead = genTreeFromVec(inp);
        TreeNode* target = getRandomNode(orighead);
        TreeNode* result = prob.getTargetCopyBFS(orighead, copyhead, target);
        EXPECT_EQ(result->val, target->val);
    }
}

struct VecIntTC{
    vector<int> tree;
    int want;
};

TEST(DeepestLeavesSum, basicTests){
    vector<VecIntTC> tcs = {
        {
            {7,4,3,INT_MIN,INT_MIN,6,19},
            25,
        },
        {
            {7},
            7,
        },
        {
            {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
            1,
        },
        {
            {1,2,3,4,5,6,7,8,9,10},
            27,
        },
        {
            {1,2,INT_MIN,3},
            3,
        },
        {
            {1,2,3,4,5,INT_MIN,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8},
            15,
        },
    };
    InterviewSolutions prob;
    for(VecIntTC tc: tcs){
        TreeNode* head = genTreeFromVec(tc.tree);
        EXPECT_EQ(prob.deepestLeavesSum(head), tc.want);
    }
}

TEST(DeepestLeavesSumDFS, basicTests){
    vector<VecIntTC> tcs = {
        {
            {7,4,3,INT_MIN,INT_MIN,6,19},
            25,
        },
        {
            {7},
            7,
        },
        {
            {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
            1,
        },
        {
            {1,2,3,4,5,6,7,8,9,10},
            27,
        },
        {
            {1,2,INT_MIN,3},
            3,
        },
        {
            {1,2,3,4,5,INT_MIN,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8},
            15,
        },
    };
    InterviewSolutions prob;
    for(VecIntTC tc: tcs){
        TreeNode* head = genTreeFromVec(tc.tree);
        EXPECT_EQ(prob.deepestLeavesSumDFS(head), tc.want);
    }
}

TEST(DeepestLeavesSumArr, basicTests){
    vector<VecIntTC> tcs = {
        {
            {1,2,3,4,5,6,7,8,9,10},
            27,
        },
        {
            {7,4,3,INT_MIN,INT_MIN,6,19},
            25,
        },
        {
            {7},
            7,
        },
        {
            {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
            1,
        },
        {
            {1,2,INT_MIN,3},
            3,
        },
        {
            {1,2,3,4,5,INT_MIN,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8},
            15,
        },
    };
    InterviewSolutions prob;
    for(VecIntTC tc: tcs){
        TreeNode* head = genTreeFromVec(tc.tree);
        EXPECT_EQ(prob.deepestLeavesSumArr(head), tc.want);
    }
}

struct Group_TC{
    vector<int> input;
    vector<vector<int>> matches;
};

TEST(GroupThePeople, basicTests){
    vector<Group_TC> tcs{
        {
            {},
            {},
        },
        {
            {1},
            {{0}},
        },
        {
            {2,1,2},
            {{1},{0,2}},
        },
        {
            {3,3,3},
            {{0,1,2}},
        },
        {
            {3,3,3,3,3,1,3},
            {{5},{0,1,2},{3,4,6}},
        },
        {
            {2,1,3,3,3,2},
            {{1},{0,5},{2,3,4}},
        },
    };
    InterviewSolutions prob;
    for(Group_TC tc: tcs){
        EXPECT_TRUE(groupMatcher(tc.matches, prob.groupThePeople(tc.input)));
    }
}

TEST(SumEvenGrandparent, basicTests){
    VecIntTC tcs[]{
        {
            {},
            0,
        },
        {
            {1},
            0,
        },
        {
            {6,7,8,2,7,1,3,9,INT_MIN,1,4,INT_MIN,INT_MIN,INT_MIN,5},
            18,
        },
        {
            {1,2,3,4,5,6,7,8,9,10},
            27,
        },
        {
            {8,4,3,INT_MIN,INT_MIN,-6,6},
            0,
        },
        {
            {8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1},
            11,
        },
        {
            {1,2,INT_MIN,3,5,-4,INT_MIN,INT_MIN,7},
            3,
        },
        {
            {1,2,3,4,5,INT_MIN,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8},
            7,
        },
    };
    InterviewSolutions prob;
    for(VecIntTC tc: tcs){
        TreeNode* h = genTreeFromVec(tc.tree);
        EXPECT_EQ(prob.sumEvenGrandparent(h), tc.want);
    }
}

struct VecVecInt{
    vector<vector<int>> in;
    int want;
};

TEST(MinTimeToVisitAllPoints, basicTest){
    VecVecInt tcs[]{
        {
            {},
            0,
        },
        {
            {{0,0}},
            0,
        },
        {
            {{0,0},{1,1}},
            1,
        },
        {
            {{1,1},{3,4},{-1,0}},
            7,
        },
        {
            {{3,2},{-2,2}},
            5,
        },
    };
    InterviewSolutions prob;
    for(VecVecInt tc: tcs){
        EXPECT_EQ(prob.minTimeToVisitAllPoints(tc.in), tc.want);
    }
}

struct StrStrTC{
    string in;
    string want;
};

TEST(freqAlphabets, basicTests){
    StrStrTC tcs[]{
        {
            "",
            "",
        },
        {
            "12345",
            "abcde",
        },
        {
            "12#315#",
            "lco",
        },
        {
            "10#11#12",
            "jkab"
        },
        {
            "1326#",
            "acz",
        },
        {
            "25#",
            "y",
        },
        {
            "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#",
            "abcdefghijklmnopqrstuvwxyz",
        },
    };
    InterviewSolutions prob;
    for(StrStrTC tc: tcs){
        EXPECT_EQ(prob.freqAlphabets(tc.in), tc.want);
    }
}

struct VecVectoVecTC{
    vector<int> tree1;
    vector<int> tree2;
    vector<int> want;
};

TEST(GetAllElements, basicTests){
    VecVectoVecTC tcs[]{
        {
            {4,2,5,1,3},
            {9,7,10,6,8},
            {1,2,3,4,5,6,7,8,9,10},
        },
        {
            {4,3,7,INT_MIN,INT_MIN,6,19},
            {6,4,7,3,INT_MIN,INT_MIN,19},
            {3,3,4,4,6,6,7,7,19,19},
        },
        {
            {7},
            {},
            {7},
        },
        {
            {},
            {},
            {},
        },
        {
            {8,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1, INT_MIN},
            {8,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1, INT_MIN},
            {1,1,2,2,3,3,4,4,5,5,6,6,8,8},
        },
        {
            {3,2,INT_MIN,1},
            {1,INT_MIN,5,2,6},
            {1,1,2,2,3,5,6},
        },
        {
            {6,3,7,2,5,INT_MIN,8,1},
            {9,4},
            {1,2,3,4,5,6,7,8,9},
        },
    };
    InterviewSolutions prob;
    for(VecVectoVecTC tc: tcs){
        TreeNode* tn1 = genTreeFromVec(tc.tree1);
        TreeNode* tn2 = genTreeFromVec(tc.tree2);
        EXPECT_THAT(prob.getAllElements(tn1, tn2), testing::ContainerEq(tc.want));
    }
}


