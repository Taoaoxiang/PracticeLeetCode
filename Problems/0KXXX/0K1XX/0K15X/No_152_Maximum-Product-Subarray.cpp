//Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//
//Example 2:
//
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Product Subarray.
//Memory Usage : 9 MB, less than 70.54% of C++ online submissions for Maximum Product Subarray.

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) { return 0; }
		int iLastMax = nums[0];
		int iLastMin = nums[0];
		int rtn = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			int iMax = max(max(iLastMax * nums[i], iLastMin * nums[i]), nums[i]);
			int iMin = min(min(iLastMax * nums[i], iLastMin * nums[i]), nums[i]);
			rtn = max(rtn, iMax);
			iLastMax = iMax;
			iLastMin = iMin;
		}
		return rtn;
	}
};