//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Your algorithm should run in O(n) complexity.
//
//Example:
//
//Input: [100, 4, 200, 1, 3, 2]
//Output: 4
//Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//

//Runtime: 928 ms, faster than 6.28% of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 10.1 MB, less than 44.26% of C++ online submissions for Longest Consecutive Sequence.

// Short and sweet?
// Nah, it's slow.
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int nMax = 0;
		unordered_set<int> uS(nums.begin(), nums.end());
		while (uS.size() > 0) {
			int i = *(uS.begin());
			uS.erase(i);
			int i2 = i - 1, i1 = i + 1;
			while (uS.find(i2) != uS.end()) { --i2; }
			while (uS.find(i1) != uS.end()) { ++i1; }
			nMax = max(nMax, i1 - i2 - 1);
		}
		return nMax;
	}
};

//Runtime: 8 ms, faster than 99.97% of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 9.1 MB, less than 96.72% of C++ online submissions for Longest Consecutive Sequence.

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() <= 1) { return nums.size(); }
		sort(nums.begin(), nums.end());
		int num = 0;
		int nMax = 0;
		for (int i = 0; i < nums.size(); ++i) {
			//cout << "i=>" << i << ", num=>" << num << endl;
			if (i == 0) { ++num; }
			else {
				if (nums[i - 1] == nums[i]) {}
				else if (nums[i - 1] + 1 == nums[i]) { ++num; }
				else {
					nMax = num > nMax ? num : nMax;
					num = 1;
				}
			}
		}
		nMax = num > nMax ? num : nMax;
		return nMax;
	}
};