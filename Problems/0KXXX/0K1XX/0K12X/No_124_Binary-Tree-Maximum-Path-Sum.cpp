//Given a non-empty binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
//Example 1:
//
//Input: [1,2,3]
//
//       1
//      / \
//     2   3
//
//Output: 6
//
//Example 2:
//
//Input: [-10,9,20,null,null,15,7]
//
//   -10
//   / \
//  9  20
//    /  \
//   15   7
//
//Output: 42
//
//

//Runtime: 36 ms, faster than 98.71% of C++ online submissions for Binary Tree Maximum Path Sum.
//Memory Usage : 25.2 MB, less than 49.56% of C++ online submissions for Binary Tree Maximum Path Sum.

class Solution {
public:
	int sum;
	int reS(TreeNode* root) {
		if (root == NULL) { return 0; }
		int iL = max(0, reS(root->left));
		int iR = max(0, reS(root->right));
		sum = max(sum, iL + iR + root->val);
		return (max(iL, iR) + root->val);
	}

	int maxPathSum(TreeNode * root) {
		sum = INT_MIN;
		reS(root);
		return sum;
	}
};