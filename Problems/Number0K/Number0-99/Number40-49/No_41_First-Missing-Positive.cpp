//Given an unsorted integer array, find the smallest missing positive integer.
//
//Example 1:
//
//Input: [1, 2, 0]
//	Output : 3
//
//	Example 2 :
//
//	Input : [3, 4, -1, 1]
//	Output : 2
//
//	Example 3 :
//
//	Input : [7, 8, 9, 11, 12]
//	Output : 1
//
//	Note :
//
//	Your algorithm should run in O(n) time and uses constant extra space.
//
//
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
//Memory Usage : 8.8 MB, less than 99.71% of C++ online submissions for First Missing Positive.

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) { return 1; }
		sort(nums.begin(), nums.end());
		vector<int>::iterator pos1 = find(nums.begin(), nums.end(), 1);
		if (pos1 != nums.end()) {
			for (; pos1 < nums.end(); ++pos1) {
				if (pos1 == nums.end() - 1) { return (*pos1) + 1; }
				else {
					if (*(pos1 + 1) - *pos1 <= 1) { continue; }
					else { return (*pos1) + 1; }
				}
			}
		}
		else { return 1; }
		return 1;
	}
};