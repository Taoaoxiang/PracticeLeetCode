//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//Example:
//
//Input: [1, 1, 2]
//	Output :
//	[
//		[1, 1, 2],
//		[1, 2, 1],
//		[2, 1, 1]
//	]
//


//Runtime: 28 ms, faster than 63.20% of C++ online submissions for Permutations II.
//Memory Usage : 10.6 MB, less than 47.08% of C++ online submissions for Permutations II.

// Apparently this nextPermutation solution is faster.
class Solution {
public:
	bool nextPermutation(vector<int>& nums) {
		int iCtrl = 0;
		while (true) {
			vector<int>::iterator it_max = max_element(nums.begin() + iCtrl, nums.end());
			if (it_max == nums.end() - 1) {
				int iTemp = *it_max;
				*it_max = *(it_max - 1);
				*(it_max - 1) = iTemp;
				break;
			}
			else {
				iCtrl = it_max - nums.begin();
				vector<int> subNums(nums.begin() + iCtrl + 1, nums.end());
				vector<int> sortDesNums(subNums);
				sort(sortDesNums.rbegin(), sortDesNums.rend());
				if (sortDesNums == subNums) {
					if (iCtrl != 0) {
						int iPop = 0;
						for (int i = nums.size() - 1; i >= iCtrl; --i) {
							if (nums[i] > nums[iCtrl - 1]) {
								iPop = i;
								break;
							}
						}
						int iTemp = nums[iPop];
						nums.erase(nums.begin() + iPop);
						nums.insert(nums.begin() + iCtrl - 1, iTemp);
						sort(nums.begin() + iCtrl, nums.end());
						break;
					}
					else { return false; }
				}
				else {
					++iCtrl;
					continue;
				}
			}
		}
		return true;
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> rtn;
		if (nums.size() == 0) { return rtn; }
		else if (nums.size() == 1) { return { nums }; }
		sort(nums.begin(), nums.end());
		rtn.push_back(nums);
		while (nextPermutation(nums) == true) { rtn.push_back(nums); }
		return rtn;
	}
};


//Runtime: 1632 ms, faster than 5.05% of C++ online submissions for Permutations II.
//Memory Usage : 55.2 MB, less than 5.85% of C++ online submissions for Permutations II.

// Quite slow???
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
		if (find(rtn.begin(), rtn.end(), tmp) == rtn.end()) { rtn.push_back(tmp); }
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
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