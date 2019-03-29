//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//Example 1:
//
//Input: nums = [5, 7, 7, 8, 8, 10], target = 8
//	Output : [3, 4]
//
//	Example 2 :
//
//	Input : nums = [5, 7, 7, 8, 8, 10], target = 6
//	Output : [-1, -1]
//

//Runtime: 20 ms, faster than 7.41% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
//Memory Usage : 10.9 MB, less than 57.76% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

// The combination of Binary Search and Recursion
// Too expensive??? (in terms of time)
// Yo, bro, it's a combo, bruh! :P
class Solution {
public:
	void recursiveSearch(int posL, int posM, int posR, vector<int>& nums, int target, vector<int>& allPos) {
		if (nums[posM] < target) {
			if (posL == posR) { return; }
			else { recursiveSearch(posM + 1, ((posM + 1) + posR) / 2, posR, nums, target, allPos); }
		}
		else if (nums[posM] > target) {
			if (posL == posR) { return; }
			else { recursiveSearch(posL, (posL + posM) / 2, posM, nums, target, allPos); }
		}
		else {
			allPos.push_back(posM);
			for (int iL = posM - 1; iL >= 0; --iL) {
				if (nums[iL] == target) { allPos.push_back(iL); }
				else { break; }
			}
			for (int iR = posM + 1; iR < nums.size(); ++iR) {
				if (nums[iR] == target) { allPos.push_back(iR); }
				else { break; }
			}
		}
		return;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0) { return { -1,-1 }; }
		else {
			vector<int> allPos;
			recursiveSearch(0, (nums.size() - 1) / 2, (nums.size() - 1), nums, target, allPos);
			if (allPos.size() == 0) { return { -1,-1 }; }
			else if (allPos.size() == 1) { return { allPos[0], allPos[0] }; }
			else {
				sort(allPos.begin(), allPos.end());
				return { allPos.front(), allPos.back() };
			}
		}
	}
};