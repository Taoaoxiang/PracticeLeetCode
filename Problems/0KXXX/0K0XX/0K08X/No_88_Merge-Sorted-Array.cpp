//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
//Note:
//
//The number of elements initialized in nums1 and nums2 are m and n respectively.
//You may assume that nums1 has enough space(size that is greater or equal to m + n) to hold additional elements from nums2.
//
//Example :
//
//	Input :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//	Output : [1, 2, 2, 3, 5, 6]
//
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
//Memory Usage : 8.6 MB, less than 100.00% of C++ online submissions for Merge Sorted Array.

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int pos = 0, i = 0;
		for (;i < n;) {
			if (pos < m) {
				if (nums2[i] <= nums1[pos]) {
					nums1.pop_back();
					nums1.insert(nums1.begin() + pos, nums2[i]);
					++i;
					++m;
				}
				else { ++pos; }
			}
			else {
				nums1.pop_back();
				nums1.insert(nums1.begin() + pos, nums2[i]);
				++i;
				++m;
			}
		}
	}
};