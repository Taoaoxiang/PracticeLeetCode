//Given n non - negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
//
//
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//
//
//
//
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//
//
//Example:
//
//Input: [2, 1, 5, 6, 2, 3]
//	Output : 10
//


//Runtime: 264 ms, faster than 16.31% of C++ online submissions for Largest Rectangle in Histogram.
//Memory Usage : 9.7 MB, less than 96.54% of C++ online submissions for Largest Rectangle in Histogram.

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int hSize = heights.size();
		if (heights.size() == 0) { return 0; }
		int iMax = 0;
		vector<int>::iterator itNext = heights.begin();
		vector<int>::iterator itR;
		vector<int>::reverse_iterator itL;
		vector<int>::iterator itBegin = heights.begin(), itEnd = heights.end();
		vector<int>::reverse_iterator itRBegin = heights.rbegin(), itREnd = heights.rend();
		while (itNext != itEnd) {
			int n = 1;
			int pos = itNext - itBegin;
			int rpos = hSize - pos - 1;
			int h = heights[pos];
			itL = find_if(itRBegin + rpos + 1, itREnd, [&h](int i) { return i < h;});
			n += (itL - itRBegin - 1) - rpos;
			itR = find_if(itBegin + pos + 1, itEnd, [&h](int i) { return i < h;});
			n += (itR - itBegin - 1) - pos;
			iMax = iMax < (n*h) ? (n*h) : iMax;
			itNext = find_if(itBegin + pos + 1, itEnd, [&h](int i) { return (i != h);});
		}
		return iMax;
	}
};

//Runtime: 264 ms, faster than 16.31% of C++ online submissions for Largest Rectangle in Histogram.
//Memory Usage : 10.3 MB, less than 67.97% of C++ online submissions for Largest Rectangle in Histogram.

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int hSize = heights.size();
		if (heights.size() == 0) { return 0; }
		vector<int> vAreas;
		vector<int>::iterator itNext = heights.begin();
		vector<int>::iterator itR;
		vector<int>::reverse_iterator itL;
		while (itNext != heights.end()) {
			int n = 1;
			int pos = itNext - heights.begin();
			int rpos = hSize - pos - 1;
			int h = heights[pos];
			itL = find_if(heights.rbegin() + rpos + 1, heights.rend(), [&h](int i) { return i < h;});
			n += (itL - heights.rbegin() - 1) - rpos;
			itR = find_if(heights.begin() + pos + 1, heights.end(), [&h](int i) { return i < h;});
			n += (itR - heights.begin() - 1) - pos;
			vAreas.push_back(n*h);
			itNext = find_if(heights.begin() + pos + 1, heights.end(), [&h](int i) { return (i != h);});
		}
		return *max_element(vAreas.begin(), vAreas.end());
	}
};