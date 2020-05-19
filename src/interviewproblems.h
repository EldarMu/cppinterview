//
// Created by Eldar Musayev on 3/7/2020.
//

#ifndef CPPINTERVIEW_INTERVIEWPROBLEMS_H
#define CPPINTERVIEW_INTERVIEWPROBLEMS_H

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>

namespace interviewproblems {
	using std::to_string;
	using std::string;
	using std::vector;
	using std::unordered_map;
	using std::priority_queue;
	using std::sort;
	using std::queue;
	using std::greater;
	using std::pair;

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  	};

	class InterviewSolutions {
	public:
		int numberOfSteps(int num);
		int numberOfStepsTwo(int num);
		vector<int> decompressRLElist(vector<int>& nums);
		vector<int> smallerNumbersThanCurrentSort(vector<int>& nums);
		vector<int> smallerNumbersThanCurrentHeap(vector<int>& nums);
		vector<int> smallerNumbersThanCurrentCountSort(vector<int>& nums);
		TreeNode* getTargetCopyRecurs(TreeNode* original, TreeNode* cloned, TreeNode* target);
		TreeNode* getTargetCopyBFS(TreeNode* original, TreeNode* cloned, TreeNode* target);
		int deepestLeavesSum(TreeNode* root);
		int deepestLeavesSumDFS(TreeNode* root);
		int deepestLeavesSumArr(TreeNode* root);
		vector<vector<int>> groupThePeople(vector<int>& groupSizes);
		int sumEvenGrandparent(TreeNode* root);
		int minTimeToVisitAllPoints(vector<vector<int>>& points);
		string freqAlphabets(string s);
		vector<int> getAllElements(TreeNode* root1, TreeNode* root2);
		bool isAlienSorted(vector<string>& words, string order);
		int getKth(int lo, int hi, int k);
		int getKthWhile(int lo, int hi, int k);
	};
}

#endif //CPPINTERVIEW_INTERVIEWPROBLEMS_H
