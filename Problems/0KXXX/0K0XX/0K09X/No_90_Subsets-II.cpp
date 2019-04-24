//Given a collection of integers that might contain duplicates, nums, return all possible subsets(the power set).
//
//Note: The solution set must not contain duplicate subsets.
//
//	Example :
//
//	Input : [1, 2, 2]
//	Output :
//	[
//		[2],
//		[1],
//		[1, 2, 2],
//		[2, 2],
//		[1, 2],
//		[]
//	]
//


//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets II.
//Memory Usage : 9.2 MB, less than 94.36% of C++ online submissions for Subsets II.

class Solution {
public:
	void reSearch(int pos, vector<int>& nums, vector<vector<int>>& rtn, vector<int> &tmp) {
		rtn.push_back(tmp);

		for (int i = pos; i < nums.size();++i) {
			if (i > pos && nums[i] == nums[i - 1]) { continue; }
			tmp.push_back(nums[i]);
			reSearch(i + 1, nums, rtn, tmp);
			tmp.pop_back();
		}
		return;
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> rtn;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		reSearch(0, nums, rtn, tmp);
		return rtn;
	}
};


//Runtime: 32 ms, faster than 5.06% of C++ online submissions for Subsets II.
//Memory Usage : 20.3 MB, less than 5.13% of C++ online submissions for Subsets II.

class Solution {
public:
	void reSearch(int pos, int iNum, int iTotal, vector<int>& nums, vector<vector<int>>& rtn, vector<int> tmp) {
		if (iNum == iTotal) {
			if (find(rtn.begin(), rtn.end(), tmp) == rtn.end()) { rtn.push_back(tmp); }
			return;
		}
		if (pos >= nums.size()) { return; }
		reSearch(pos + 1, iNum, iTotal, nums, rtn, tmp);
		tmp.push_back(nums[pos]);
		reSearch(pos + 1, iNum + 1, iTotal, nums, rtn, tmp);
		return;
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> rtn;
		sort(nums.begin(), nums.end());
		for (int i = 0; i <= nums.size(); ++i) {
			if (i == 0) { rtn.push_back({}); }
			else if (i == nums.size()) { rtn.push_back(nums); }
			else {
				reSearch(0, 0, i, nums, rtn, {});
			}
		}
		return rtn;
	}
};