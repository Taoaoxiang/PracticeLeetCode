//Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.Return the sum of the three integers.You may assume that each input would have exactly one solution.
//
//Example:
//
//Given array nums = [-1, 2, 1, -4], and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int rtn = 0;
		if (nums.size() <= 3) {
			for (std::vector<int>::iterator it = nums.begin();it != nums.end();++it) { rtn += *it; }
			return rtn;
		}
		else {
			std::sort(nums.begin(), nums.end());
			std::vector<int>::iterator it_l = nums.begin();
			std::vector<int>::iterator it_i, it_r;
			int i1, i2, i3, iSum;
			int i_abs_min = pow(2, 31) - 1;
			int i_abs = pow(2, 31) - 1;
			while (it_l < nums.end()) {
				i1 = *it_l;
				it_r = nums.end() - 1;
				//cout << "T0: Lef=>" << i1 << endl;
				while (it_r > it_l) {
					it_i = it_l + 1;
					i3 = *it_r;
					while (it_i < it_r) {
						i2 = *it_i;
						iSum = i1 + i2 + i3;
						//cout << "T1: SUM=>" << iSum << endl;
						i_abs = abs(iSum - target);
						//cout << "T2: ABS=>" << i_abs << endl;
						if (i_abs < i_abs_min) {
							rtn = iSum;
							i_abs_min = i_abs;
						}
						while ((it_i < it_r) && (*it_i == i2)) { ++it_i; }
					}
					while ((it_l < it_r) && (*it_r == i3)) { --it_r; }
				}
				while ((it_l < nums.end()) && (*it_l == i1)) { ++it_l; }
			}
		}
		return rtn;
	}
};