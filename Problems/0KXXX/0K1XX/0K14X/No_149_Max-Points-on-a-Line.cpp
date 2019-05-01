//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
//Example 1:
//
//Input: [[1,1],[2,2],[3,3]]
//Output: 3
//Explanation:
//^
//|
//|        o
//|     o
//|  o  
//+------------->
//0  1  2  3  4
//
//Example 2:
//
//Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//Output: 4
//Explanation:
//^
//|
//|  o
//|     o        o
//|        o
//|  o        o
//+------------------->
//0  1  2  3  4  5  6
//
//NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.


//Runtime: 12 ms, faster than 97.46% of C++ online submissions for Max Points on a Line.
//Memory Usage : 9 MB, less than 80.46% of C++ online submissions for Max Points on a Line.

class Solution {
public:
	int maxPoints(vector<vector<int>>& points) {
		if (points.size() <= 2) { return points.size(); }
		map<pair<int, int>, int> uAll;
		for (int iL = 0; iL < points.size(); ++iL) {
			pair<int, int> tmpP = { points[iL][0], points[iL][1] };
			if (uAll.find(tmpP) != uAll.end()) { ++uAll[tmpP]; }
			else { uAll[tmpP] = 1; }
		}
		int rtn = 0;
		for (auto itL = uAll.begin(); itL != uAll.end(); ++itL) {
			int rtn_tmp = itL->second;
			auto itR = uAll.end();
			--itR;
			long x1 = itL->first.first, y1 = itL->first.second;
			//cout << "x1=>" << x1 << ", y1=>" << y1 << endl;
			for (; itR != itL; --itR) {
				int rtn_tmp2 = rtn_tmp + itR->second;
				long x2 = itR->first.first - x1, y2 = itR->first.second - y1;
				//cout << "x2=>" << itR->first.first << ", y2=>" << itR->first.second << endl;
				auto itM = itL;
				++itM;
				for (; itM != itR; ++itM) {
					long x3 = itM->first.first - x1, y3 = itM->first.second - y1;
					if (y2 * x3 == y3 * x2) {
						//cout << "x3=>" << itM->first.first << ", y3=>" << itM->first.second << endl;
						rtn_tmp2 += itM->second;
					}
				}
				//cout << "p: " << rtn_tmp2 << endl;
				rtn = max(rtn, rtn_tmp2);
			}
			rtn = max(rtn, rtn_tmp);
		}
		return rtn;
	}
};