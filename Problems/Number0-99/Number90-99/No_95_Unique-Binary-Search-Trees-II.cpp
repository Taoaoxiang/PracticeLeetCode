//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, null, 3, 2],
//		[3, 2, null, 1],
//		[3, 1, null, null, 2],
//		[2, 1, 3],
//		[1, null, 2, null, 3]
//	]
//	   Explanation:
//				  The above output corresponds to the 5 unique BST's shown below:
//
//					  1         3     3      2      1
//					  \       /     /      / \      \
//					  3     2     1      1   3      2
//					  /     /       \                 \
//					  2     1         2                 3
//


//Runtime: 32 ms, faster than 20.19% of C++ online submissions for Unique Binary Search Trees II.
//Memory Usage : 16.3 MB, less than 82.78% of C++ online submissions for Unique Binary Search Trees II.

class Solution {
public:
	vector<TreeNode*> genTree(int iC, int n) {
		vector<TreeNode*> rtn;
		if (iC > n) { return { NULL }; }
		else if (iC == n) { return { new TreeNode(iC) }; }
		for (int i = iC; i <= n; ++i) {
			vector<TreeNode*> vecL = genTree(iC, i - 1);
			vector<TreeNode*> vecR = genTree(i + 1, n);
			for (int jL = 0; jL < vecL.size();++jL) {
				for (int jR = 0; jR < vecR.size();++jR) {
					TreeNode* tmp = new TreeNode(i);
					tmp->left = vecL[jL];
					tmp->right = vecR[jR];
					rtn.push_back(tmp);
				}
			}
		}
		return rtn;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) { return {}; }
		return genTree(1, n);
	}
};