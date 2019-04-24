//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//
//	The solution set must not contain duplicate quadruplets.
//
//	Example :
//
//	Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	A solution set is :
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]
//


//Runtime: 36 ms, faster than 74.93% of C++ online submissions for 4Sum.
//Memory Usage : 8.9 MB, less than 100.00% of C++ online submissions for 4Sum.

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> rtn;
		if (nums.size() < 4) { return rtn; }
		else {
			std::sort(nums.begin(), nums.end());
			std::vector<int>::iterator it_l = nums.begin();
			std::vector<int>::iterator it_li, it_ri, it_r;
			int i1, i2, i3, i4, iSum;
			while (it_l < nums.end()) {
				i1 = *it_l;
				//cout << "T0: Lef=>" << i1 << endl;
				it_r = nums.end() - 1;
				while (it_r > it_l + 2) {
					i4 = *it_r;
					//cout << "T1: Rig=>" << i4 << endl;
					it_li = it_l + 1;
					it_ri = it_r - 1;
					while (it_li < it_ri) {
						i2 = *it_li;
						i3 = *it_ri;
						//cout << "T3: =>" << i3 << endl;
						//cout << "T4: =>" << i4 << endl;
						iSum = i1 + i2 + i3 + i4;
						if (iSum > target) { --it_ri; }
						else if (iSum < target) { ++it_li; }
						else {
							rtn.push_back({ i1, i2, i3, i4 });
							while ((it_li < it_ri) && (*it_ri == i3)) { --it_ri; }
							while ((it_li < it_ri) && (*it_li == i2)) { ++it_li; }
						}
					}
					while ((it_li < it_r) && (*it_r == i4)) { --it_r; }
				}
				while ((it_l < nums.end()) && (*it_l == i1)) { ++it_l; }
			}
		}
		return rtn;
	}
};