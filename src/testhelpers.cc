#include "interviewproblems.h"
#include "testhelpers.h"

using namespace interviewproblems;

TreeNode* interviewproblems::genTreeFromVec(std::vector<int> vals){
    if(vals.size()==0 || vals[0]==NULL){return NULL;}

    std::queue<TreeNode*> q;
    int ptr = 0; 
    TreeNode* head = NULL;
    
    while(ptr < vals.size()){
        if(q.size()==0){
            TreeNode *t = new TreeNode(vals[ptr]);
            head = t;
            q.push(t);
            ptr++;
        } else{
            TreeNode* tn = q.front();
            q.pop();
            if(ptr < vals.size() && vals[ptr]!=NULL){
                TreeNode *l = new TreeNode(vals[ptr]);
                tn->left = l;
                q.push(l);
            }
            ptr++;
            if(ptr < vals.size() && vals[ptr]!=NULL){
                TreeNode *r = new TreeNode(vals[ptr]);
                tn->right = r;
                q.push(r);
            }
            ptr++;
        }
    }
    return head;
}

void interviewproblems::recursAddNodes(TreeNode* tn, std::vector<TreeNode*> &nodes){
    if(tn!=NULL){
        nodes.push_back(tn);
    }
    TreeNode* left = tn->left;
    if(left != NULL){
        recursAddNodes(left, nodes);
    }
    TreeNode* right = tn->right;
    if(right != NULL){
        recursAddNodes(right, nodes);
    }
}

TreeNode* interviewproblems::getRandomNode(TreeNode* head){
    std::vector<TreeNode*> allNodes;
    recursAddNodes(head, allNodes);
    int rval = std::rand()%allNodes.size();
    return allNodes[rval];
}



