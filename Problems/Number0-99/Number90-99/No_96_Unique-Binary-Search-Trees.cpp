//Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
//Example:
//
//Input: 3
//	Output : 5
//	Explanation :
//	Given n = 3, there are a total of 5 unique BST's:
//
//	1         3     3      2      1
//	\       /     /      / \      \
//	3     2     1      1   3      2
//	/     /       \                 \
//	2     1         2                 3
//


//Runtime: 1488 ms, faster than 7.16% of C++ online submissions for Unique Binary Search Trees.
//Memory Usage : 8.2 MB, less than 56.05% of C++ online submissions for Unique Binary Search Trees.

class Solution {
public:
	int catalan(int n) {
		if (n <= 1) { return 1; }
		unsigned int rtn = 0;
		for (int i = 0; i < n; ++i) {
			rtn += catalan(i)*catalan(n - i - 1);
		}
		return rtn;
	}

	int numTrees(int n) {
		return catalan(n);
	}

};