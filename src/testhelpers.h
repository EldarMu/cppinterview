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
}

#endif //CPPINTERVIEW_TESTHELPERS_H