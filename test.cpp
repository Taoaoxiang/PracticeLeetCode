#include "include_LeetCode.h"


//
//class Solution {
//public:
//	int candy(vector<int>& ratings) {
//		int nums = ratings.size();
//		if ( nums == 0) { return 0; }
//		else if (nums == 1) { return 1; }
//		else if (nums == 2) {
//			if (ratings[0] == ratings[1]) { return 2; }
//			else { return 3; }
//		}
//		else {
//			int rtn = 0;
//
//
//
//			sort(ratings.begin(), ratings.end());
//			int iLast = INT_MIN;
//			int iCandy = 0;
//			for (int i = 0; i < nums; ++i) {
//				if (ratings[i] > iLast) {
//					++iCandy;
//					iLast = ratings[i];
//				}
//				else {
//					if (iCandy - 1 > 0) { --iCandy; }
//				}
//				rtn += iCandy;
//			}
//			return rtn;
//		}
//	}
//};


class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {}

	void push(int x) {
		s.push(x);
		if (sMin.empty() || x <= sMin.top()) { sMin.push(x); }
	}

	void pop() { 
		if (s.top() == sMin.top()) { sMin.pop(); }
		s.pop();
	}

	int top() { return s.top(); }

	int getMin() { return sMin.top(); }

private:
	stack<int> s, sMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




int main() {




	std::cout << "Wuzup world!" << std::endl;
	return 0;
}