// This name 3Sum is apparently for adult who's playing wild.
// :P

//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.
//
//Note :
//
//	The solution set must not contain duplicate triplets.
//
//	Example :
//
//	Given array nums = [-1, 0, 1, 2, -1, -4],
//
//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]
//

//Runtime: 92 ms, faster than 99.97% of C++ online submissions for 3Sum.
//Memory Usage : 14.5 MB, less than 99.80% of C++ online submissions for 3Sum.

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> rtn;
		std::sort(nums.begin(), nums.end());
		if (nums.size() < 3) { return rtn; }
		else {
			std::vector<int>::iterator it_l = nums.begin();
			std::vector<int>::iterator it_i, it_r;
			int i1, i2, i3, iSum;
			while ((it_l < nums.end()) && (*it_l <= 0)) {
				i1 = *it_l;
				it_i = it_l + 1;
				it_r = nums.end() - 1;
				while (it_i < it_r) {
					i2 = *it_i;
					i3 = *it_r;
					iSum = i1 + i2 + i3;
					if (iSum > 0) { --it_r; }
					else if (iSum < 0) { ++it_i; }
					else {
						rtn.push_back({ i1, i2, i3 });
						while ((it_i < it_r) && (*it_i == i2)) { ++it_i; }
						while ((it_i < it_r) && (*it_r == i3)) { --it_r; }
					}
				}
				while ((it_l < nums.end()) && (*it_l == i1)) { ++it_l; }
			}
		}
		return rtn;
	}
};