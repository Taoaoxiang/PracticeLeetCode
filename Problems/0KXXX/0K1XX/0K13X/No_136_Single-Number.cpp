//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//
//Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
//Example 1:
//
//Input: [2,2,1]
//Output: 1
//
//Example 2:
//
//Input: [4,1,2,1,2]
//Output: 4
//
//

//Runtime: 16 ms, faster than 97.68% of C++ online submissions for Single Number.
//Memory Usage : 9.9 MB, less than 25.05% of C++ online submissions for Single Number.

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int r = 0;
		for (int i = 0; i < nums.size(); ++i) {
			r ^= nums[i];
		}
		return r;
	}
};

//Runtime: 24 ms, faster than 39.31% of C++ online submissions for Single Number.
//Memory Usage : 11.5 MB, less than 14.66% of C++ online submissions for Single Number.

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		unordered_set<int> uS;
		for (int i = 0; i < nums.size(); ++i) {
			if (uS.find(nums[i]) != uS.end()) { uS.erase(nums[i]); }
			else { uS.insert(nums[i]); }
		}
		return *uS.begin();
	}
};

//Runtime: 196 ms, faster than 5.32% of C++ online submissions for Single Number.
//Memory Usage : 9.8 MB, less than 26.88% of C++ online submissions for Single Number.
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		while (nums.size() > 0) {
			int i = nums.back();
			nums.pop_back();
			vector<int>::iterator it = find(nums.begin(), nums.end(), i);
			if (it != nums.end()) { nums.erase(it); }
			else { return i; }
		}
		return 0;
	}
};

//Runtime: 256 ms, faster than 5.32% of C++ online submissions for Single Number.
//Memory Usage : 9.7 MB, less than 63.75% of C++ online submissions for Single Number.

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
			vector<int>::iterator it2 = find(it + 1, nums.end(), *it);
			if (it2 != nums.end()) {
				nums.erase(it2);
			}
			else { return *it; }
		}
		return 0;
	}
};