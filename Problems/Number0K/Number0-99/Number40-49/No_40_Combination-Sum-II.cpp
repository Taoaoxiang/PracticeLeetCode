//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//
//Example 1 :
//
//	Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//	A solution set is :
//[
//	[1, 7],
//	[1, 2, 5],
//	[2, 6],
//	[1, 1, 6]
//]
//
//Example 2:
//
//Input: candidates = [2, 5, 2, 1, 2], target = 5,
//	A solution set is :
//	   [
//		   [1, 2, 2],
//		   [5]
//	   ]
//

// My slow version
class Solution {
public:
	void checkSubStr2(vector<int>& candidates, int iForward, int rRemainder, int i0, int iPop, vector<int> vecIn, vector<vector<int>>& rtn) {
		if (iForward < 0) {
			if ((rRemainder == 0) && (find(rtn.begin(), rtn.end(), vecIn) == rtn.end())) { rtn.push_back(vecIn); }
			return;
		}
		if ((rRemainder == 0) && (find(rtn.begin(), rtn.end(), vecIn) == rtn.end())) {
			rtn.push_back(vecIn);
			return;
		}
		else {
			if (candidates[iForward] > rRemainder) {
				if (candidates[iForward] == i0) { return; }
				else {
					checkSubStr2(candidates, iForward - 1, rRemainder, i0, iPop, vecIn, rtn);
					return;
				}
			}
			else {
				checkSubStr2(candidates, iForward - 1, rRemainder, i0, iPop, vecIn, rtn);
				vecIn.push_back(candidates[iForward]);
				checkSubStr2(candidates, iForward - 1, rRemainder - candidates[iForward], i0, iPop, vecIn, rtn);
				return;
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else {
			checkSubStr2(candidates, candidates.size() - 1, target, candidates[0], -1, vector<int>(), rtn);
		}
		return rtn;
	}
};

// Slower modification
class Solution {
public:
	void checkSubStr2(vector<int>& candidates, int iForward, int rRemainder, vector<int> vecIn, vector<vector<int>>& rtn) {
		if (iForward < 0) {
			if ((rRemainder == 0) && (find(rtn.begin(), rtn.end(), vecIn) == rtn.end())) { rtn.push_back(vecIn); }
			return;
		}
		if (rRemainder == 0) {
			if (find(rtn.begin(), rtn.end(), vecIn) != rtn.end()) { return; }
			else {
				rtn.push_back(vecIn);
				return;
			}
		}
		else {
			if (candidates[iForward] > rRemainder) {
				checkSubStr2(candidates, iForward - 1, rRemainder, vecIn, rtn);
				return;
			}
			else {
				checkSubStr2(candidates, iForward - 1, rRemainder, vecIn, rtn);
				vecIn.push_back(candidates[iForward]);
				checkSubStr2(candidates, iForward - 1, rRemainder - candidates[iForward], vecIn, rtn);
				return;
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else {
			checkSubStr2(candidates, candidates.size() - 1, target, vector<int>(), rtn);
		}

		return rtn;
	}
};
