//
// Created by Eldar Musayev on 5/11/2020.
//


#ifndef CPPINTERVIEW_TESTHELPERS_H
#define CPPINTERVIEW_TESTHELPERS_H

#include "interviewproblems.h"

namespace interviewproblems {
    TreeNode* genTreeFromVec(std::vector<int> vals);
    TreeNode* getRandomNode(TreeNode* head);
    void recursAddNodes(TreeNode* tn, std::vector<TreeNode*> &nodes);
    bool groupMatcher(vector<vector<int>> want, vector<vector<int>> got);
    bool two_d_vector_comparer(vector<vector<int>> got, vector<vector<int>> want);
    ListNode* genLinkedListFromVector(vector<int> in);
}

#endif //CPPINTERVIEW_TESTHELPERS_H