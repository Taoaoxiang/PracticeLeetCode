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
			if (height[height.size()-1] == 0) { height.erase(height.end()-1); }
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


int main() {

	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };

	int ret = Solution().trap(height);


	cout << ret << endl;

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}