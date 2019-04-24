//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., [0, 0, 1, 2, 2, 5, 6] might become[2, 5, 6, 0, 0, 1, 2]).
//
//You are given a target value to search.If found in the array return true, otherwise return false.
//
//Example 1:
//
//Input: nums = [2, 5, 6, 0, 0, 1, 2], target = 0
//	Output : true
//
//	Example 2 :
//
//	Input : nums = [2, 5, 6, 0, 0, 1, 2], target = 3
//	Output : false
//
//	Follow up :
//
//	   This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
//		   Would this affect the run - time complexity ? How and why ?
//


//Runtime: 8 ms, faster than 99.55% of C++ online submissions for Search in Rotated Sorted Array II.
//Memory Usage : 8.8 MB, less than 18.45% of C++ online submissions for Search in Rotated Sorted Array II.

// What we need to focus is the side of "Sorted" part
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0) { return false; }
		int iL = 0, iR = nums.size() - 1;
		int iMid;
		while (iL < iR) {
			iMid = (iL + iR) / 2;
			if (nums[iMid] == target) { return true; }
			if (nums[iMid] < nums[iR]) {
				if (target > nums[iMid] && target <= nums[iR]) { iL = iMid + 1; }
				else { iR = iMid; }
			}
			else if (nums[iMid] > nums[iR]) {
				if (target < nums[iMid] && target >= nums[iL]) { iR = iMid; }
				else { iL = iMid + 1; }
			}
			else { --iR; }
		}

		if (nums[iL] == target) { return true; }
		else { return false; }
	}
};