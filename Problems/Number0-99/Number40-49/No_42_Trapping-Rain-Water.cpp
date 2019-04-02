//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
//The above elevation map is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.Thanks Marcos for contributing this image!
//
//Example:
//
//Input: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//	Output : 6
//


//Runtime: 56 ms, faster than 7.80% of C++ online submissions for Trapping Rain Water.
//Memory Usage : 9 MB, less than 100.00% of C++ online submissions for Trapping Rain Water.

// My slow version, but memory saving :p
class Solution {
public:
	void findNPop(vector<int>& height, int &rtn) {
		while (height.size() > 0) {
			if (height[0] == 0) { height.erase(height.begin()); }
			else if (height[0] < 0) {
				rtn -= height[0];
				height.erase(height.begin());
			}
			else { break; }
		}
		while (height.size() > 0) {
			if (height[height.size() - 1] == 0) { height.erase(height.end() - 1); }
			else if (height[height.size() - 1] <= 0) {
				rtn -= height[height.size() - 1];
				height.erase(height.end() - 1);
			}
			else { break; }
		}
		return;
	}

	int trap(vector<int>& height) {
		int rtn = 0;
		vector<int>::iterator it0;
		while (height.size() > 0) {
			findNPop(height, rtn);
			if (height.size() == 0) { break; }
			int h;
			if (height[0] < height[height.size() - 1]) { h = height[0]; }
			else { h = height[height.size() - 1]; }
			transform(height.begin(), height.end(), height.begin(), bind2nd(plus<int>(), -h));
		}

		return rtn;
	}
};