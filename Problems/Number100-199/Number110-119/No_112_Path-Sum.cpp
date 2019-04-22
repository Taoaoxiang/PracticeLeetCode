//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/   / \
//	11  13  4
//	/ \      \
//	7    2      1
//
//	return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.
//

//Runtime: 16 ms, faster than 99.49% of C++ online submissions for Path Sum.
//Memory Usage : 19.9 MB, less than 40.40% of C++ online submissions for Path Sum.

class Solution {
public:
	bool reS(TreeNode* root, int sum) {
		if (root == NULL) { return false; }
		else if (root->val == sum && (root->left == NULL && root->right == NULL)) { return true; }
		else {
			return reS(root->left, sum - root->val) || reS(root->right, sum - root->val);
		}
	}

	bool hasPathSum(TreeNode* root, int sum) {
		return reS(root, sum);
	}
};