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