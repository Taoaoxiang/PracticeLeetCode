Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers(including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1 :

	Input : candidates = [2, 3, 6, 7], target = 7,
	A solution set is :
[
	[7],
	[2, 2, 3]
]

Example 2:

Input: candidates = [2, 3, 5], target = 8,
	A solution set is :
	   [
		   [2, 2, 2, 2],
		   [2, 3, 3],
		   [3, 5]
	   ]



// Faster version
class Solution {
public:
	void checkSubStr(vector<int>& candidates, int iForward, int rRemainder, vector<int> vecIn, vector<vector<int>>& rtn) {
		if (iForward < 0) {
			if (rRemainder == 0) { rtn.push_back(vecIn); }
			return;
		}
		if (rRemainder == 0) {
			rtn.push_back(vecIn);
			return;
		}
		else {
			if (candidates[iForward] > rRemainder) {
				checkSubStr(candidates, iForward - 1, rRemainder, vecIn, rtn);
				return;
			}
			checkSubStr(candidates, iForward - 1, rRemainder, vecIn, rtn);
			int iTime = rRemainder / candidates[iForward];
			for (int i = iTime; i > 0;--i) {
				int iRemain = rRemainder - i * candidates[iForward];
				vector<int> vecTemp(i, candidates[iForward]);
				vecTemp.insert(vecTemp.end(), vecIn.begin(), vecIn.end());
				checkSubStr(candidates, iForward - 1, iRemain, vecTemp, rtn);
			}
			return;
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else if (candidates.size() == 1) {
			if (target%candidates.back() == 0) { rtn.push_back(vector<int>(target / candidates.back(), candidates.back())); }
			return rtn;
		}
		else {
			for (int i = candidates.size() - 1; i >= 0; --i) {
				for (int iTime = target / candidates[i]; iTime > 0; --iTime) {
					checkSubStr(candidates, i - 1, (target - candidates[i] * iTime), vector<int>(iTime, candidates[i]), rtn);
				}
			}

		}
		return rtn;
	}
};



// Slower version
class Solution {
public:
	void checkSubStr(vector<int>& candidates, int iForward, int rRemainder, vector<int> vecIn, vector<vector<int>>& rtn) {
		if (iForward < 0) {
			if (rRemainder == 0) { rtn.push_back(vecIn); }
			return;
		}
		if (rRemainder == 0) {
			rtn.push_back(vecIn);
			return;
		}
		else {
			if (candidates[iForward] > rRemainder) {
				checkSubStr(candidates, iForward - 1, rRemainder, vecIn, rtn);
				return;
			}
			checkSubStr(candidates, iForward - 1, rRemainder, vecIn, rtn);
			int iTime = rRemainder / candidates[iForward];
			for (int i = iTime; i > 0;--i) {
				int iRemain = rRemainder - i * candidates[iForward];
				vector<int> vecTemp(i, candidates[iForward]);
				vecTemp.insert(vecTemp.end(), vecIn.begin(), vecIn.end());
				checkSubStr(candidates, iForward - 1, iRemain, vecTemp, rtn);
			}
			return;
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else if (candidates.size() == 1) {
			if (target%candidates.back() == 0) { rtn.push_back(vector<int>(target / candidates.back(), candidates.back())); }
			return rtn;
		}
		else { checkSubStr(candidates, candidates.size() - 1, target, {}, rtn); }
		return rtn;
	}
};