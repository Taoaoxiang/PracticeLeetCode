//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//
//[
//     [2],
//    [3,4],
//   [6,5,7],
//  [4,1,8,3]
//]
//
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


//Runtime: 8 ms, faster than 99.48% of C++ online submissions for Triangle.
//Memory Usage : 9.7 MB, less than 99.44% of C++ online submissions for Triangle.

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 1) { return triangle[0][0]; }
		for (int i = 1; i < triangle.size();++i) {
			for (int pos = 0; pos < triangle[i].size(); ++pos) {
				if (pos == 0) { triangle[i][pos] += triangle[i - 1][pos]; }
				else if (pos == triangle[i].size() - 1) { triangle[i][pos] += triangle[i - 1][pos - 1]; }
				else {
					triangle[i][pos] += (triangle[i - 1][pos - 1] < triangle[i - 1][pos] ? triangle[i - 1][pos - 1] : triangle[i - 1][pos]);
				}
			}
		}
		return *min_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
	}
};