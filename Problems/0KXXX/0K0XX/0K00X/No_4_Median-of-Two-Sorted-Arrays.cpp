//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//You may assume nums1 and nums2 cannot be both empty.
//
//Example 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> num_all;
		int i_num = nums1.size() + nums2.size();
		//std::cout << "T1: " << i_num << std::endl;
		num_all.reserve(i_num);
		num_all.insert(num_all.end(), nums1.begin(), nums1.end());
		num_all.insert(num_all.end(), nums2.begin(), nums2.end());

		std::sort(num_all.begin(), num_all.end());
		double rtn;
		if (i_num % 2 == 1) {
			rtn = num_all[i_num / 2];
		}
		else
		{
			rtn = (num_all[i_num / 2] + num_all[i_num / 2 - 1]) / 2.0;
		}
		return rtn;
	}
};