//Given an integer array nums, find the contiguous subarray(containing at least one number) which has the largest sum and return its sum.
//
//Example:
//
//Input: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//	Output : 6
//	Explanation : [4, -1, 2, 1] has the largest sum = 6.
//
//	Follow up :
//
//	   If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

//Runtime: 8 ms, faster than 99.42% of C++ online submissions for Maximum Subarray.
//Memory Usage : 9.1 MB, less than 99.75% of C++ online submissions for Maximum Subarray.

// This idea is not originally from me. Lesson learnt.
// Thank you to LeetCode contributors.
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) { return nums.back(); }
		int rtn = INT_MIN, iSum = 0;
		for (int i = 0;i < nums.size();++i) {
			int iTry = iSum + nums[i];
			if (iTry > rtn) { rtn = iTry; }

			if (iTry < 0) { iSum = 0; }
			else { iSum = iTry; }
		}
		return rtn;
	}
};


//Runtime: 12 ms, faster than 80.79% of C++ online submissions for Maximum Subarray.
//Memory Usage : 9.1 MB, less than 99.75% of C++ online submissions for Maximum Subarray.

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) { return nums.back(); }
		int rtn, iLast;
		for (int i = 0;i < nums.size();++i) {
			if (i == 0) { iLast = nums[i]; rtn = iLast; }
			else {
				if (nums[i] >= 0) {
					if (iLast >= 0) { iLast += nums[i]; }
					else { iLast = nums[i]; }
				}
				else {
					if (iLast + nums[i] >= 0) { iLast += nums[i]; }
					else { iLast = nums[i]; }
				}
				if (iLast > rtn) { rtn = iLast; }
			}
		}
		return rtn;
	}
};
