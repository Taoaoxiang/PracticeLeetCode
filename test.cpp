#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	//void vecOut(vector<int>& in) {
	//	cout << "Current vec: ";
	//	for (int i = 0; i < in.size(); ++i) { cout << in[i] << ", "; }
	//	cout << endl;
	//}
	
	void checkSubStr2(vector<int>& candidates, int iForward, int rRemainder, vector<int> vecIn, vector<vector<int>>& rtn) {
		if (iForward < 0) {
			if ((rRemainder == 0) && (find(rtn.begin(), rtn.end(), vecIn)==rtn.end())) { rtn.push_back(vecIn); }
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
				checkSubStr2(candidates, iForward - 1, rRemainder- candidates[iForward], vecIn, rtn);
				return;
			}
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else {
			checkSubStr2(candidates, candidates.size()-1, target, vector<int>(), rtn);
		}

		return rtn;
	}
};



int main() {

	vector<int> can = { 8, 2, 3, 6, 7, 9 };
	can = { 2, 3, 6, 7 };
	can = { 7,3,2 };
	int target = 8;
	target = 7;
	target = 18;
	Solution().combinationSum2(can, target);

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}