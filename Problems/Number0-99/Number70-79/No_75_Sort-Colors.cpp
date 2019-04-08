//Given an array with n objects colored red, white or blue, sort them in - place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note: You are not suppose to use the library's sort function for this problem.
//
//	Example :
//
//	Input : [2, 0, 2, 1, 1, 0]
//	Output : [0, 0, 1, 1, 2, 2]
//
//	Follow up :
//
//A rather straight forward solution is a two - pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//Could you come up with a one - pass algorithm using only constant space ?



//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sort Colors.
//Memory Usage : 8.8 MB, less than 7.16% of C++ online submissions for Sort Colors.

// The "follow up" asks for one-pass algorithm, there you go then. :P
class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() < 2) { return; }
		int pos = 0, pos2 = nums.size() - 1;
		while (pos <= pos2) {
			if (nums[pos] == 0) {
				nums.erase(nums.begin() + pos);
				nums.insert(nums.begin(), 0);
				++pos;
			}
			else if (nums[pos] == 1) { ++pos; }
			else if (nums[pos] == 2) {
				nums.push_back(2);
				nums.erase(nums.begin() + pos);
				--pos2;
			}
		}
		return;
	}
};