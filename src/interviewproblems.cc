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
vector<int> InterviewSolutions::decompressRLElist(vector<int>& nums) {
    vector<int> res;
    res.reserve(1024);
    bool isFreq = true;
    int freq;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
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
vector<int> InterviewSolutions::smallerNumbersThanCurrentSort(vector<int>& nums) {
    unordered_map<int, vector<int>> ixsForVal;
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(ixsForVal.count(v) == 0){
            ixsForVal.insert({v, {i}});
        } else {
            ixsForVal.at(v).push_back(i);
        }
    }
    vector<int> res(nums.size());
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(i==0 || nums.at(i-1) != v){
            vector<int> ixs = ixsForVal.at(v);
            for(int ix: ixs){
                res.at(ix) = i; 
            }
        }
    }
    return res;    
}

// same as above but just using maxHeap
// the exact same result performance-wise.. ok
vector<int> InterviewSolutions::smallerNumbersThanCurrentHeap(vector<int>& nums) {
    vector<int> res(nums.size());
    unordered_map<int, vector<int>> ixsForVal;
    for(int i = 0; i < nums.size(); i++){
        int v = nums.at(i);
        if(ixsForVal.find(v) == ixsForVal.end()){
            ixsForVal.insert({v, {i}});
        } else {
            ixsForVal.at(v).push_back(i);
        }
    }
    priority_queue<int> pq;
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
        vector<int> ixs = ixsForVal.at(val);
        for(int ix: ixs){
            res.at(ix) = pq.size();
        }
    }
    return res;
}

// same problem but let's try counting sort, knowing that max val is 100
// 8 ms, faster than 98% of solutions
vector<int> InterviewSolutions::smallerNumbersThanCurrentCountSort(vector<int>& nums) {
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
    vector<int> res(nums.size());
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
    queue<TreeNode*> q;
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

// given a tree, return the sum of the values of the lowest level
// seemed obvious to use a two queue bfs approach, 
// performance is mediocre (56ms, beats 44% of c++ solutions)
int InterviewSolutions::deepestLeavesSum(TreeNode* root) {
    if(!root){ return 0; }
    queue<TreeNode*> curLevel;
    curLevel.push(root);
    int sum = 0;
    while(curLevel.size() != 0){
        sum = 0;
        int len = curLevel.size();
        for(int i=0; i<len; i++){
            TreeNode* tn = curLevel.front();
            curLevel.pop();
            sum += tn->val;
            if(tn->left){
                curLevel.push(tn->left);
            }
            if(tn->right){ 
                curLevel.push(tn->right);
            }
        }
    }
    return sum;
}

// same but with dfs, basically the same results
void recursSum(TreeNode* tn, int level, vector<int>* sums){
    if(!tn) {return;}
    if(sums->size()<=level){
        sums->push_back(tn->val);
    } else {
        sums->at(level)+= tn->val;
    }
    if(tn->left){ recursSum(tn->left, level+1, sums); }
    if(tn->right){ recursSum(tn->right, level+1, sums); }
}

int InterviewSolutions::deepestLeavesSumDFS(TreeNode* root){
    vector<int>* sums = new vector<int>();
    sums->reserve(100);
    recursSum(root, 0, sums);
    if(sums->size()==0) { return 0; }
    return sums->at(sums->size()-1);
}

// the exact same performance as before
// at this point I'm certain leetcode isn't measuring c++ performance correctly
int recursLowestLevel(TreeNode* tn, int curLevel, int (&levels)[10000]){
    levels[curLevel] += tn->val;
    int l = curLevel;
    if(tn->left){ l = recursLowestLevel(tn->left, curLevel+1, levels); }
    int r = curLevel;
    if(tn->right){ r = recursLowestLevel(tn->right, curLevel+1, levels); }
    if(r > l){
        return r;
    }
    return l;
}

int InterviewSolutions::deepestLeavesSumArr(TreeNode* root){
    if(!root) { return 0; }
    // problem condition of max tree nodes being 10,000 or less
    const int MAX_TREE_LEVELS = 10000;
    int levels[MAX_TREE_LEVELS] = {0};
    return levels[recursLowestLevel(root, 0, levels)];
}

// given an array where index is id and val is size of group,
// return valid groups of ids. Problem constrained to valid inputs
// 24 ms, faster than 89% of c++ solutions
vector<vector<int>> InterviewSolutions::groupThePeople(vector<int>& groupSizes) {
    int sz = groupSizes.size();
    vector<vector<int>> result;
    result.reserve(sz);
    unordered_map<int, vector<int>> m;
    m.reserve(sz);
    for(int i=0; i<sz; i++){
        int val = groupSizes[i];
        if(m.find(val) == m.end()){
            vector<int> v;
            v.push_back(i);
            m.insert({val, v});
        } else {
            int vsz = m.at(val).size();
            if(vsz<val){
                m.at(val).push_back(i);
            } else {
                result.push_back(m.at(val));
                vector<int> nv;
                nv.push_back(i);
                m.insert_or_assign(val, nv);
            }
        }
    }
    for (auto& it: m){
        result.push_back(it.second);
    }
    return result;            
}

// get sum of tree nodes with even-valued grandparent
// let's start off with simple dfs
// 48ms beats 79% of c++ solutions
void recursSumNodesGP(TreeNode* tn, bool evenGP, bool evenP, int (&sum)[1]){
    if(!tn){ return; }
    if(evenGP){ sum[0] += tn->val; }
    bool curEven = tn->val%2 == 0;
    recursSumNodesGP(tn->left, evenP, curEven, sum);
    recursSumNodesGP(tn->right, evenP, curEven, sum);
}

int InterviewSolutions::sumEvenGrandparent(TreeNode* root) {
    int sum[1]{0};
    recursSumNodesGP(root, false, false, sum);
    return sum[0];
}

// given a vector of 2d points to visit in order,
// with one step either horizontal, vertical, or diagonal (1,0),(0,1),(1,1)
// return the minimum number of steps
// 8 ms, beats 94% of solutions, because I declare no vars in loop
int InterviewSolutions::minTimeToVisitAllPoints(vector<vector<int>>& points) {
    if(points.size()<2){ return 0; }
    auto it = points.begin();
    int prevX = it->at(0);
    int prevY = it->at(1);
    it++;
    int curX = 0;
    int curY = 0;
    int diffX = 0;
    int diffY = 0;
    int steps = 0;
    for(it; it!=points.end(); it++){
        curX = it->at(0);
        curY = it->at(1);
        diffX = abs(curX-prevX);
        diffY = abs(curY-prevY);
        if(diffY>diffX){
            steps += diffY;
        } else {
            steps += diffX;
        }
        prevX = curX;
        prevY = curY;
    }
    return steps;         
}

// given a string of digits with a # to indicate the last two digits
// are part of a longer digit, convert 1->a 10->j... and return as string
// done as string replace and ascii table shifts relying on valid ascii input
string InterviewSolutions::freqAlphabets(string s) {
    int sz = s.size();
    if(sz==0){ return s; }
    for(int i = sz-1; i>=0; i--){
        if(s[i]=='#'){
            s.replace(i-2, 3, 1, stoi(s.substr(i-2, 2))+96);
            i -= 2;
        } else {
            s[i] += 48;
        }
    }
    return s;    
}
void inOrderTr(TreeNode* tn, vector<int>& vec){
    if(!tn){ return; }
    inOrderTr(tn->left, vec);
    vec.push_back(tn->val);
    inOrderTr(tn->right, vec);
}

// given two trees, return their values in sorted order
// 240 ms, beats 84% of c++ solutions
vector<int> InterviewSolutions::getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    if(!root1 && !root2){ return res; }
    vector<int> v1;
    vector<int> v2;
    inOrderTr(root1, v1);
    inOrderTr(root2, v2);
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    res.reserve(v1.size()+v2.size());
    while(it1 != v1.end() || it2 != v2.end()){
        if(it1 != v1.end() && it2 != v2.end()){
            if(*it1>*it2){
                res.push_back(*it2);
                it2++;
            } else {
                res.push_back(*it1);
                it1++;
            }
        } else if(it1 != v1.end()){
            res.push_back(*it1);
            it1++;
        } else {
            res.push_back(*it2);
            it2++;
        }
    }
    return res;
}

// aliens use the english lower-case alphabet, but the words
// are in different order. check if vec of words is sorted
// completely average solution beating 57% of c++ solutions
// still neat to implement my own comparator though
bool alienWordIsGreater(string s1, string s2, unordered_map<char, int>& m){
    int minSize = s1.size()<s2.size()? s1.size():s2.size();
    for(int i=0; i<minSize; i++){
        int v1 = m[s1[i]];
        int v2 = m[s2[i]];
        if(v1<v2){
            return false;
        } else if(v1>v2){
            return true;
        }
    }
    return s1.size()>s2.size();

}

bool InterviewSolutions::isAlienSorted(vector<string>& words, string order) {
    if(words.size()<2){ return true; }
    unordered_map<char, int> m;
    int iter = 0;
    for(char c: order){
        m.insert({c, iter});
        iter++;
    }
    for(int i=0; i<words.size()-1; i++){
        if(alienWordIsGreater(words[i], words[i+1], m)){ return false; }
    }
    return true;
}

// sort elements by power value, return kth element (1-indexed)
// dynamic programming is clearly a good call here
// made way faster (beats 55% now) at half memory footprint
int getPower(int n, short powers[300000]){
    if(n==1){return 0;}
    if(powers[n]!= 0){ return powers[n]; }
    if(n%2==0){
        powers[n] = 1 + getPower(n/2, powers);
    } else {
        powers[n] = 1 + getPower(3*n+1, powers);
    }
    return powers[n];
}

class pairComparator{ 
public: 
    int operator() (const pair<int, int>& p1, const pair<int, int>& p2) { 
        if(p1.first == p2.first){
            return p1.second > p2.second;
        } else {
            return p1.first > p2.first;
        }
    } 
};

int InterviewSolutions::getKth(int lo, int hi, int k) {
    short powers[300000] = {0};
    priority_queue<pair<int,int>, vector<pair<int,int>>, pairComparator> pq;
    for(int i = lo; i<=hi; i++){
        pq.push({getPower(i, powers), i});
    }
    for(int i=1; i<k; i++){
        pq.pop();
    }
    return pq.top().second;

}


// given a string of directions (N,S,E,W) each taking 1 step, return if
// the created path crosses itself at any point.
// 8 ms so not the fastest but interesting to make a custom hash function
pair<int, int> move(pair<int, int>& tu, char c){
    switch(c){
        case 'N': 
            tu.first+=1;
            break;
        case 'S':
            tu.first-=1;
            break;
        case 'W':
            tu.second-=1;
            break;
        case 'E':
            tu.second+=1;
            break; 
    }
    return tu;
}

bool InterviewSolutions::isPathCrossing(string path) {
    pair<int, int> loc(0,0);
    size_t locHash = hash<int>{}(loc.first) ^ (hash<int>{}(loc.second) << 1);
    std::unordered_set<size_t> visited;
    visited.insert(locHash);
    for(char c: path){
        loc = move(loc, c);
        locHash = hash<int>{}(loc.first) ^ (hash<int>{}(loc.second) << 1);
        if(visited.find(locHash) != visited.end()){
            return true;
        }
        visited.insert(locHash);
    }
    return false;
}

// given a matrix of int "colors", a point in the matrix and a new color
// return after recoloring that point and all points of the same color 
// connected to it via a same-color path
// basic recursive solution, 16 ms, beats 78% of c++ solutions
vector<vector<int>> InterviewSolutions::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if(image.size() == 0 || image.at(0).size() == 0){
        return image;
    }
    int oldColor = image.at(sr).at(sc);
    image.at(sr).at(sc) = newColor;
    if(oldColor == newColor){
        return image;
    }
    vector<pair<int,int>> dirs = {
        {1,0},
        {-1,0},
        {0,1},
        {0, -1},
    };

    for(pair<int, int> dir: dirs){
        pair<int,int> offset = {dir.first+sr, dir.second+sc};
        if(offset.first >= 0 && offset.first < image.size() 
        && offset.second >= 0 && offset.second < image.at(0).size()
        && image.at(offset.first).at(offset.second) == oldColor){
            floodFill(image, offset.first, offset.second, newColor);
        }
    }
    return image;
}

// find if the set of characters in ransomnote is a subset of magazine
// works, slow though, 64 ms so beats only 39% of c++ solutions
// but it does work and is very readable
bool InterviewSolutions::canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> letters;
    for(char c: magazine){
        letters[c]++;
    }
    for(char c: ransomNote){
        if(letters.find(c) == letters.end() || letters[c] == 0){
            return false;
        }
        letters[c]--;
    }
    return true;
}

// once more but just using ascii codes
// knocked time down to 44 ms, beats 65% of c++ solutions
bool InterviewSolutions::canConstructAscii(string ransomNote, string magazine) {
    int letters[128] = {0};
    for(char c: magazine){
        letters[c]++;
    }
    for(char c: ransomNote){
        if(letters[c]<=0){return false;}
        letters[c]--;
    }
    return true;
}

// basic solution to merge two lists problem
// really slow though
ListNode* InterviewSolutions::mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr){
        return l2;
    } else if(l2 == nullptr){
        return l1;
    }
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    while(l1 != nullptr || l2 != nullptr){
        if(l1 == nullptr){
            cur->next = l2;
            l2 = nullptr;
        } else if(l2 == nullptr){
            cur->next = l1;
            l1 = nullptr;
        } else{
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
    }
    return head->next;
}

// return the biggest sum of the counts of two elements
// whose difference is exactly 1.
// Basic solution with hashmap and checking for the biggest value every time
// very slow solution
int InterviewSolutions::findLHS(vector<int>& nums) {
    std::unordered_map<int, int> number_counts;
    int biggest_count = 0;
    for(int i: nums){
        if(number_counts.find(i) == number_counts.end()){
            number_counts[i] = 1; 
        } else {
            number_counts[i]++;
        }
        if(number_counts.find(i-1) != number_counts.end() &&
        number_counts[i-1]+number_counts[i] > biggest_count){
            biggest_count = number_counts[i-1] + number_counts[i];
        }
        if(number_counts.find(i+1) != number_counts.end() &&
        number_counts[i+1]+number_counts[i] > biggest_count){
            biggest_count = number_counts[i] + number_counts[i+1];
        }
    }
    return biggest_count;        
}