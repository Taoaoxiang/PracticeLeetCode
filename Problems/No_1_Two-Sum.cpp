//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rtn;
		for (int i = 0;i != nums.size();++i) {
			for (int i2 = 0;i2 != nums.size();++i2) {
				if (i != i2) {
					int sum = nums[i] + nums[i2];
					if (sum == target) {
						rtn = { i, i2 };
						return rtn;
					}

				}
			}
		}
		return rtn;
	}
};