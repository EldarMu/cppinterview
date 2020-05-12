#include "interviewproblems.h"

using namespace interviewproblems;


// Given a number, find the number of steps required to bring that number to 0
// the only steps allowed are division by two and subtraction by one.
// Solution 1, the most obvious one, still as fast as it gets (0 ms).
int InterviewSolutions::numberOfSteps(int num) {
    int cnt = 0;
    while (num > 0) {
        if (num % 2 == 0) {
            num /= 2;
            cnt++;
        }
        else {
            num -= 1;
            cnt++;
        }
    }
    return cnt;
}
// Solution 2, same thing but with binary operations, no difference since 0 ms.
int InterviewSolutions::numberOfStepsTwo(int num) {
    int cnt = 0;
    while (num > 0) {
        if (num % 2 == 0) {
            num >>= 1;
            cnt++;
        }
        else {
            num ^= 1;
            cnt++;
        }
    }
    return cnt;
}
// Given a vector of values and frequencies f1, v1, f2, v2, write out the full list of values.
// Really just getting familiar with C++ syntax here as the problem is trivial.
// Faster than 97.43% of solutions, largely thanks to reserving capacity.
std::vector<int> InterviewSolutions::decompressRLElist(std::vector<int>& nums) {
    std::vector<int> res;
    res.reserve(1024);
    bool isFreq = true;
    int freq;
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
        if (isFreq) {
            isFreq = false;
            freq = *it;
        }
        else {
            isFreq = true;
            for (int i = 0; i < freq; i++) {
                res.push_back(*it);
            }
        }
    }
    return res;
}

// given arr of nums, return arr corresponding to number of elems in arr smaller than elem at that index
// solution 1 uses the standard sorting algorithm and produces results according to first index of a value
// only beats 54% of solutions, beats 100% in terms of memory usage
std::vector<int> InterviewSolutions::smallerNumbersThanCurrentSort(std::vector<int>& nums) {
    std::unordered_map<int, std::vector<int>> ixsForVal;
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(ixsForVal.count(v) == 0){
            ixsForVal.insert({v, {i}});
        } else {
            ixsForVal.at(v).push_back(i);
        }
    }
    std::vector<int> res(nums.size());
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(i==0 || nums.at(i-1) != v){
            std::vector<int> ixs = ixsForVal.at(v);
            for(int ix: ixs){
                res.at(ix) = i; 
            }
        }
    }
    return res;    
}

// same as above but just using maxHeap
// the exact same result performance-wise.. ok
std::vector<int> InterviewSolutions::smallerNumbersThanCurrentHeap(std::vector<int>& nums) {
    std::vector<int> res(nums.size());
    std::unordered_map<int, std::vector<int>> ixsForVal;
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(ixsForVal.find(v) == ixsForVal.end()){
            ixsForVal.insert({v, {i}});
        } else {
            ixsForVal.at(v).push_back(i);
        }
    }
    std::priority_queue<int> pq;
    for(int n: nums){
        pq.push(n);
    }
    int curVal = INT_MIN;
    while(pq.size() != 0){
        int val = pq.top();
        pq.pop();
        while(pq.size() != 0 && val == pq.top()){
            pq.pop();
        }
        curVal = val;
        std::vector<int> ixs = ixsForVal.at(val);
        for(int ix: ixs){
            res.at(ix) = pq.size();
        }
    }
    return res;
}

// same problem but let's try counting sort, knowing that max val is 100
// 8 ms, faster than 98% of solutions
std::vector<int> InterviewSolutions::smallerNumbersThanCurrentCountSort(std::vector<int>& nums) {
    const int MAXVAL = 101;
    int vals[MAXVAL] = {0};
    for(int n: nums){
        vals[n]++;
    }
    int smallerVals = 0;
    for(int i=0; i<MAXVAL; i++){
        if(vals[i] > 0){
            int curVal = vals[i];
            vals[i] = smallerVals;
            smallerVals += curVal;
        }
    }
    std::vector<int> res(nums.size());
    for(int i=0; i<nums.size(); i++){
        res[i] = vals[nums[i]];
    }
    return res;
}

// basic find val in binary tree (not BST). In this case we get a clone of the tree 
// but it doesn't matter since duplicate vals aren't allowed
// 696 ms, faster than 69% of solutions. Going to try a BFS in a while loop
TreeNode* recursFindNode(TreeNode* tn, int val){
    int curVal = tn->val;
    if(curVal==val){
        return tn;
    }
    if(tn->left != NULL){
        TreeNode* left = recursFindNode(tn->left, val);
        if(left!=NULL){return left;}
    }
    if(tn->right != NULL){
        TreeNode* right = recursFindNode(tn->right, val);
        if(right != NULL){return right;}
    }    
    return NULL;
}
TreeNode* InterviewSolutions::getTargetCopyRecurs(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    int val = target->val;
    if(cloned==NULL){return cloned;}
    return recursFindNode(cloned, val);
}

// same but BFS with some loop unrolling, 712 ms. 
// same code in golang runs in 0 ms. Something's wonky with leetcode's c++ runtime
TreeNode* InterviewSolutions::getTargetCopyBFS(TreeNode* original, TreeNode* cloned, TreeNode* target){
    if(target==NULL || original==NULL || cloned==NULL){ return NULL; }
    int v = target->val;
    std::queue<TreeNode*> q;
    q.push(cloned);
    while(q.size()!=0){
        TreeNode* cur = q.front();
        q.pop();
        if(cur->val == v){ return cur; }
        TreeNode* l = cur->left;
        if(l != NULL){
            if(l->val == v){ return l; }
            if(l->left != NULL){ q.push(l->left); }
            if(l->right != NULL){ q.push(l->right); }
        }
        
        TreeNode* r = cur->right;
        if(r != NULL){
            if(r->val == v){ return r; }
            if(r->left != NULL){ q.push(r->left); }
            if(r->right != NULL){ q.push(r->right); }
        }
    }
    return NULL;
}
