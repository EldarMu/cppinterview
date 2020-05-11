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