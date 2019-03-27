//Given a sorted array nums, remove the duplicates in - place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//
//Example 1:
//
//Given nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//
//It doesn't matter what you leave beyond the returned length.
//
//Example 2:
//
//Given nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//
//It doesn't matter what values are set beyond the returned length.
//
//Clarification:
//
//Confused why the returned value is an integer but your answer is an array ?
//
//Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
//Internally you can think of this :
//
//	// nums is passed in by reference. (i.e., without making a copy)
//	int len = removeDuplicates(nums);
//
//// any modification to nums in your function would be known by the caller.
//// using the length returned by your function, it prints the first len elements.
//for (int i = 0; i < len; i++) {
//	print(nums[i]);
//}
//


//Runtime: 160 ms, faster than 18.03% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage : 10 MB, less than 99.11% of C++ online submissions for Remove Duplicates from Sorted Array.

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) { return 0; }
		else if (nums.size() == 1) { return 1; }
		int iTemp;
		int rtn = 0;
		int ii = 0;
		while (ii < nums.size()) {
			if (ii == 0) {
				iTemp = nums[ii];
				rtn += 1;
				++ii;
			}
			else {
				if (nums[ii] == iTemp) {
					nums.erase(nums.begin() + ii);
				}
				else {
					iTemp = nums[ii];
					rtn += 1;
					++ii;
				}
			}

		}

		return rtn;
	}
};