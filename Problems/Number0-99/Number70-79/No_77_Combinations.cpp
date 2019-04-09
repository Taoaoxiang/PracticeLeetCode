//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
//Example:
//
//Input: n = 4, k = 2
//	Output :
//	[
//		[2, 4],
//		[3, 4],
//		[2, 3],
//		[1, 2],
//		[1, 3],
//		[1, 4],
//	]
//


//Runtime: 84 ms, faster than 77.40% of C++ online submissions for Combinations.
//Memory Usage : 20.5 MB, less than 25.00% of C++ online submissions for Combinations.

class Solution {
public:
	void reCom(int pos, int n, int k, vector<int> tmp, vector<vector<int>> &rtn) {
		if (k == 0) {
			rtn.push_back(tmp);
			return;
		}
		for (int i = pos; i <= n - k + 1; ++i) {
			vector<int> tmp2(tmp);
			tmp2.push_back(i);
			reCom(i + 1, n, k - 1, tmp2, rtn);
		}
		return;
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> rtn;
		if (k == 0) { return rtn; }
		if (k == 1) {
			for (int i = 1; i <= n; ++i) { rtn.push_back({ i }); }
			return { rtn };
		}
		if (k == n) {
			vector<int> tmp;
			for (int i = 1; i <= n; ++i) { tmp.push_back(i); }
			return { tmp };
		}
		else { reCom(1, n, k, {}, rtn); }
		return rtn;
	}
};