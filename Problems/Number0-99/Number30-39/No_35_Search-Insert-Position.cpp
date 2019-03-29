//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1, 3, 5, 6], 5
//	Output : 2
//
//	Example 2 :
//
//	Input : [1, 3, 5, 6], 2
//	Output : 1
//
//	Example 3 :
//
//	Input : [1, 3, 5, 6], 7
//	Output : 4
//
//	Example 4 :
//
//	Input : [1, 3, 5, 6], 0
//	Output : 0
//


//Runtime: 8 ms, faster than 98.45% of C++ online submissions for Search Insert Position.
//Memory Usage : 8.8 MB, less than 98.32% of C++ online submissions for Search Insert Position.

// Combo for Dumbo. :P
// Combination of Binary Search and Recursion
class Solution {
public:
	int recursiveSearch(int posL, int posM, int posR, vector<int>& nums, int target) {
		if (nums[posM] < target) {
			if (posL == posR) { return posM + 1; }
			else { return recursiveSearch(posM + 1, ((posM + 1) + posR) / 2, posR, nums, target); }
		}
		else if (nums[posM] > target) {
			if (posL == posR) { return posM; }
			else { return recursiveSearch(posL, (posL + posM) / 2, posM, nums, target); }
		}
		else { return posM; }
	}

	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0) { return 0; }
		return recursiveSearch(0, (nums.size() - 1) / 2, nums.size() - 1, nums, target);
	}
};