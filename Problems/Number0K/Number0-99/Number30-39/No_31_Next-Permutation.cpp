//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place and use only constant extra memory.
//
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1


//Runtime: 12 ms, faster than 97.23% of C++ online submissions for Next Permutation.
//Memory Usage : 9 MB, less than 98.94% of C++ online submissions for Next Permutation.

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) { return; }

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
					else {
						sort(nums.begin(), nums.end());
						break;
					}
				}
				else {
					++iCtrl;
					continue;
				}
			}
		}
		return;
	}
};