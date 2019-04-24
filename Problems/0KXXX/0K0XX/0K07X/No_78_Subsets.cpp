//Given a set of distinct integers, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : nums = [1, 2, 3]
//	Output :
//	[
//		[3],
//		[1],
//		[2],
//		[1, 2, 3],
//		[1, 3],
//		[2, 3],
//		[1, 2],
//		[]
//	]
//


//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
//Memory Usage : 9.6 MB, less than 23.78% of C++ online submissions for Subsets.

class Solution {
public:
	void reCom(int pos, vector<int>& nums, int k, vector<int> tmp, vector<vector<int>> &rtn) {
		if (k == 0) {
			rtn.push_back(tmp);
			return;
		}
		for (int i = pos; i < nums.size() - k + 1; ++i) {
			vector<int> tmp2(tmp);
			tmp2.push_back(nums[i]);
			reCom(i + 1, nums, k - 1, tmp2, rtn);
		}
		return;
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> rtn;
		if (nums.size() == 0) { return { {} }; }
		else if (nums.size() == 1) { return { {}, nums }; }
		else {
			for (int i = 0; i <= nums.size(); ++i) {
				if (i == 0) { rtn.push_back({}); }
				else if (i == nums.size()) { rtn.push_back(nums); }
				else { reCom(0, nums, i, {}, rtn); }
			}
			return rtn;
		}
	}
};