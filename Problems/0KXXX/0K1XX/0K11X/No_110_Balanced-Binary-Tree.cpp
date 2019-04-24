//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as :
//
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example 1 :
//
//	Given the following tree[3, 9, 20, null, null, 15, 7] :
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//
//	Return true.
//
//	Example 2:
//
//Given the following tree[1, 2, 2, 3, 3, null, null, 4, 4] :
//
//	1
//	/ \
//	2   2
//	/ \
//	3   3
//	/ \
//	4   4
//
//	Return false.
//

//Runtime: 16 ms, faster than 99.48% of C++ online submissions for Balanced Binary Tree.
//Memory Usage : 16.2 MB, less than 100.00% of C++ online submissions for Balanced Binary Tree.

class Solution {
public:
	int reLen(TreeNode* root, int lev) {
		if (root == NULL) { return lev; }
		int lenL = reLen(root->left, lev + 1);
		int lenR = reLen(root->right, lev + 1);
		int re = lenL - lenR;
		if (re == 0) { return lenL; }
		else if (re == 1) { return lenL; }
		else if (re == -1) { return lenR; }
		else { return 0; }
	}

	bool isBalanced(TreeNode* root) {
		return reLen(root, 1);
	}
};