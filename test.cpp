#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	int vecSum(vector<int>& Can) {
		int rtn = 0;
		for (int i = 0; i < Can.size(); ++i) { rtn += Can[i]; }
		return rtn;
	}

	//checkSubStr(vector<int>(candidates.begin() + i), target)
	void checkSubStr(vector<int>& subCan, int target, vector<vector<int>>& rtn) {
		int iLast = subCan.back();
		int iRemain = target % iLast;
		int iTime = target / iLast;
		vector<int> vecTemp(iTime, iLast);
		for (int i = subCan.size() - 1; i >= 0; --i) {
			if (iRemain == 0) {
				rtn.push_back(vecTemp);
				vecTemp.erase[0];
				if (vecTemp.size() == 0) { break; }
				else {
					if (vecTemp[0] != iLast) { break; }
					else {


					}
				}
			}
			else {


			}
		
		}


		while (true) {
			if (iRemain == 0) {
				rtn.push_back(vecTemp);
				vecTemp.erase[0];
				if (vecTemp.size() == 0) { break; }
				else {
					if (vecTemp[0] != iLast) { break; }
					else {
						

					}
				}
			}
			else {
			
			
			}
		
		}

		return;
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
			for (int i = candidates.size() -1 ; i>=0; --i) {
				if (candidates[i] > target) { continue; }
				else {
					checkSubStr(vector<int>(candidates.begin(), candidates.begin()+i+1), target, rtn);
				}
			}
		
		}
		return rtn;
	}
};



int main() {

	vector<int> can = { 8, 2, 3, 6, 7, 9 };
	int target = 8;
	Solution().combinationSum(can, target);

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}