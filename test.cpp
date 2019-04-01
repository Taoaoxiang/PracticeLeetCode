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
				int iRemain = rRemainder - i*candidates[iForward];
				vector<int> vecTemp(i, candidates[iForward]);
				vecTemp.insert(vecTemp.end(), vecIn.begin(), vecIn.end());
				//vecOut(vecTemp);
				checkSubStr(candidates, iForward - 1,  iRemain, vecTemp, rtn);
			}
			return;
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> rtn;
		sort(candidates.begin(), candidates.end());
		if (candidates.size() == 0) { return rtn; }
		else if (candidates.size() == 1) {
			if (target%candidates.back() == 0) { rtn.push_back(vector<int>(target/candidates.back(), candidates.back())); }
			return rtn;
		}
		else {
			checkSubStr(candidates, candidates.size() - 1, target, vector<int>(), rtn);
			//for (int i = candidates.size() - 1; i >= 0; --i) {
			//	checkSubStr(candidates, i, target, vector<int>(), rtn);
			//	//for (int iTime = target / candidates[i]; iTime > 0; --iTime) {
			//	//	checkSubStr(candidates, i-1, (target-candidates[i]*iTime), vector<int>(iTime, candidates[i]), rtn);
			//	//}
			//}
		
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
	Solution().combinationSum(can, target);

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}