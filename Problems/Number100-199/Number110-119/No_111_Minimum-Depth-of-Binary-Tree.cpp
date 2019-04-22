//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//
//	return its minimum depth = 2.


//Runtime: 24 ms, faster than 21.56% of C++ online submissions for Minimum Depth of Binary Tree.
//Memory Usage : 19.4 MB, less than 95.64% of C++ online submissions for Minimum Depth of Binary Tree.

class Solution {
public:
	int reS(TreeNode* root, int lev) {
		if (root->left == NULL && root->right == NULL) { return lev; }
		else if (root->left == NULL && root->right != NULL) { return reS(root->right, lev + 1); }
		else if (root->left != NULL && root->right == NULL) { return reS(root->left, lev + 1); }
		else {
			int lenL = reS(root->left, lev + 1);
			int lenR = reS(root->right, lev + 1);
			return (lenL < lenR ? lenL : lenR);
		}
	}

	int minDepth(TreeNode* root) {
		if (root == NULL) { return 0; }
		return reS(root, 1);
	}
};