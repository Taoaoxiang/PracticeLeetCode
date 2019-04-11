#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

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

int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}