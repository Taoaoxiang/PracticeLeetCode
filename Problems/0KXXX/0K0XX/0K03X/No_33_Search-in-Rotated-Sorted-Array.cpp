//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//Example 1:
//
//Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//	Output : 4
//
//	Example 2 :
//
//	Input : nums = [4, 5, 6, 7, 0, 1, 2], target = 3
//	Output : -1
//
//
//
//Runtime: 8 ms, faster than 96.91% of C++ online submissions for Search in Rotated Sorted Array.
//Memory Usage : 8.6 MB, less than 100.00% of C++ online submissions for Search in Rotated Sorted Array.

// Is this a trap or something?
// People are using binary search.
class Solution {
public:
	int search(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size();++i) {
			if (nums[i] == target) {
				return i;
			}
		}
		return -1;
	}
};