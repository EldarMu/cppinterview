#include "interviewproblems.h"
#include "testhelpers.h"

using namespace interviewproblems;

TreeNode* interviewproblems::genTreeFromVec(std::vector<int> vals){
    if(vals.size()==0 || vals[0]==INT_MIN){return NULL;}

    queue<TreeNode*> q;
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
            if(ptr < vals.size() && vals[ptr]!=INT_MIN){
                TreeNode *l = new TreeNode(vals[ptr]);
                tn->left = l;
                q.push(l);
            }
            ptr++;
            if(ptr < vals.size() && vals[ptr]!=INT_MIN){
                TreeNode *r = new TreeNode(vals[ptr]);
                tn->right = r;
                q.push(r);
            }
            ptr++;
        }
    }
    return head;
}

void interviewproblems::recursAddNodes(TreeNode* tn, vector<TreeNode*> &nodes){
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
    vector<TreeNode*> allNodes;
    recursAddNodes(head, allNodes);
    int rval = rand()%allNodes.size();
    return allNodes[rval];
}

// generates a string of all possible number order matches
// then compares with received vectors to make sure each one is present
// instead of trying to compare each vector in "want" to each vector in "got"
// simply treat them as strings, toss in a map, mark present if found
// at the end just check if any expected matches weren't found
bool interviewproblems::groupMatcher(vector<vector<int>> want, vector<vector<int>> got){
    unordered_map<string, bool> wanted;
    for(vector<int> v: want){
        string s;
        for(int n: v){
            s.append(to_string(n));
        }
        wanted.insert({s, false});
    }
    for(vector<int>v: got){
        string s;
        for(int n:v){
            s.append(to_string(n));
        }
        if(wanted.find(s) == wanted.end()){
            return false;
        }
        wanted[s] = true;
    }
    for(auto& it: wanted){
        if(it.second==false){
            return false;
        }
    }
    return true;
}

// compares two rectangular vector matrices
bool interviewproblems::two_d_vector_comparer(vector<vector<int>> got, vector<vector<int>> want){
    if(got.size() != want.size() || got.at(0).size() != want.at(0).size()){
        return false;
    }
    int row_len = want.size();
    int col_len = want.at(0).size();
    for(int i = 0; i < row_len; i++){
        for(int j =0; j < col_len; j++){
            if(want.at(i).at(j)!=got.at(i).at(j)){
                return false;
            }
        }
    }
    return true;
}

ListNode* interviewproblems::genLinkedListFromVector(vector<int> in){
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(int i: in){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode* ret = head->next;
    delete head;
    return ret;
}



