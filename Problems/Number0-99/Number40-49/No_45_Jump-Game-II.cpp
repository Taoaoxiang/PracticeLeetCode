//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//Example:
//
//Input: [2, 3, 1, 1, 4]
//	Output : 2
//	Explanation : The minimum number of jumps to reach the last index is 2.
//	Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//	Note :
//
//	You can assume that you can always reach the last index.
//

//Runtime: 20 ms, faster than 41.15% of C++ online submissions for Jump Game II.
//Memory Usage : 10.1 MB, less than 99.68% of C++ online submissions for Jump Game II.

class Solution {
public:
	int jump(vector<int>& nums) {
		int numsSize = nums.size();
		if (numsSize <= 1) { return 0; }

		int pos = 0;
		int num = nums[pos];
		int rtn = 0;
		while (pos < numsSize - 1) {
			if (pos + num >= numsSize - 1) { return ++rtn; }
			int maxI = -1, maxPos = -1;
			for (int i = pos + num; i > pos; --i) {
				if (nums[i] + i > maxI + maxPos) {
					maxI = nums[i];
					maxPos = i;
				}
			}
			num = maxI;
			pos = maxPos;
			++rtn;
		}
		return rtn;
	}
};