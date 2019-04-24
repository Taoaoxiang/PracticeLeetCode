//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.In how many distinct ways can you climb to the top ?
//
//Note : Given n will be a positive integer.
//
//	Example 1 :
//
//	Input : 2
//	Output : 2
//	Explanation : There are two ways to climb to the top.
//	1. 1 step + 1 step
//	2. 2 steps
//
//	Example 2 :
//
//	Input : 3
//	Output : 3
//	Explanation : There are three ways to climb to the top.
//	1. 1 step + 1 step + 1 step
//	2. 1 step + 2 steps
//	3. 2 steps + 1 step
//


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Climbing Stairs.
//Memory Usage : 8.5 MB, less than 55.44% of C++ online submissions for Climbing Stairs.

class Solution {
public:
	int climbStairs(int n) {
		vector<int> vec(n + 1, 0);
		for (int i = 0; i <= n; ++i) {
			if (i == 0 || i == 1) { vec[i] = 1; }
			else { vec[i] = vec[i - 1] + vec[i - 2]; }
		}
		return vec[n];
	}
};