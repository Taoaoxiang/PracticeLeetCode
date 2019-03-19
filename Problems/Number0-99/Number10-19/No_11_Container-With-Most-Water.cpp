//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.
//
//
//
//	The above vertical lines are represented by array[1, 8, 6, 2, 5, 4, 8, 3, 7].In this case, the max area of water(blue section) the container can contain is 49.
//
//
//
//	Example:
//
//	Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//		Output : 49
//
//

// This one is (slightly) faster than bottom one
class Solution {
public:
	int maxArea(vector<int>& height) {
		int h_len = height.size();
		long rtn = 0;
		long curArea = 0;
		for (int l = 0; l != h_len;++l) {
			for (int r = h_len - 1;r != l;--r) {
				if (height[l] >= height[r]) { curArea = (r - l)*(height[r]); }
				else { curArea = (r - l)*(height[l]); }
				if (rtn < curArea) { rtn = curArea; }
			}
		}
		return rtn;
	}
};

// This one is slower?
class Solution {
public:
	int maxArea(vector<int>& height) {
		int h_len = height.size();
		long rtn = 0;
		long curArea = 0;
		for (int l = 0; l != h_len;++l) {
			for (int r = h_len - 1;r != l;--r) {
				curArea = (r - l) * min(height[l], height[r]);
				rtn = max(rtn, curArea);
			}
		}
		return rtn;
	}
};
