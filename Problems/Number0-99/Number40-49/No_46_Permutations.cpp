//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1, 2, 3]
//	Output :
//	[
//		[1, 2, 3],
//		[1, 3, 2],
//		[2, 1, 3],
//		[2, 3, 1],
//		[3, 1, 2],
//		[3, 2, 1]
//	]
//

// The two solutions below are only for UNIQUE integers in the list

//Runtime: 20 ms, faster than 24.11% of C++ online submissions for Permutations.
//Memory Usage : 9.6 MB, less than 43.99% of C++ online submissions for Permutations.

// To generate the nth permutation. Seems like a little bit slower than the recursive version.
class Solution {
public:
	void nthPermutation(int n, int iFact, vector<int> nums, vector<vector<int>> &rtn) {
		vector<int> tmp;
		int quo;
		while (nums.size() > 0) {
			iFact /= nums.size();
			quo = n / iFact;
			tmp.push_back(nums[quo]);
			nums.erase(nums.begin() + quo);
			n %= iFact;
		}
		rtn.push_back(tmp);
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> rtn;
		if (nums.size() == 0) { return rtn; }
		else if (nums.size() == 1) { return { nums }; }
		int iFact = 1;
		for (int i = nums.size(); i > 1; --i) { iFact *= i; }
		for (int i = 0;i < iFact;++i) {
			nthPermutation(i, iFact, nums, rtn);
		}
		return rtn;
	}
};


//Runtime: 16 ms, faster than 53.95% of C++ online submissions for Permutations.
//Memory Usage : 10.8 MB, less than 12.57% of C++ online submissions for Permutations.

// Recursive version to generate all permutations. Okay speed.
class Solution {
public:
	void recursiveGen(vector<int> add, vector<int> passVec, vector<vector<int>> &rtn) {
		if (passVec.size() == 0) {
			rtn.push_back(add);
		}
		else {
			for (int i = 0; i < passVec.size();++i) {
				vector<int> passVec2(passVec);
				vector<int> add2(add);
				add2.push_back(passVec2[i]);
				passVec2.erase(passVec2.begin() + i);
				recursiveGen(add2, passVec2, rtn);
			}
		}
		return;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> rtn;
		if (nums.size() == 0) { return rtn; }
		else if (nums.size() == 1) { return { nums }; }
		recursiveGen({}, nums, rtn);
		return rtn;
	}
};