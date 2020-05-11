//
// Created by Eldar Musayev on 3/7/2020.
//

#ifndef CPPINTERVIEW_INTERVIEWPROBLEMS_H
#define CPPINTERVIEW_INTERVIEWPROBLEMS_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

namespace interviewproblems {
	class InterviewSolutions {
	public:
		int numberOfSteps(int num);
		int numberOfStepsTwo(int num);
		std::vector<int> decompressRLElist(std::vector<int>& nums);
		std::vector<int> smallerNumbersThanCurrentSort(std::vector<int>& nums);
		std::vector<int> smallerNumbersThanCurrentHeap(std::vector<int>& nums);
	};
}

#endif //CPPINTERVIEW_INTERVIEWPROBLEMS_H
