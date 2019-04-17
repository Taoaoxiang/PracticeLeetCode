//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
//
//Example 1:
//
//Input:
//2
/// \
//1   3
//Output: true
//
//	Example 2 :
//
//	5
//	/ \
//	1   4
//	/ \
//	3   6
//	Output: false
//	Explanation : The input is : [5, 1, 4, null, null, 3, 6].The root node's value
//	is 5 but its right child's value is 4.



//Runtime: 28 ms, faster than 19.88% of C++ online submissions for Validate Binary Search Tree.
//Memory Usage : 20.6 MB, less than 57.88% of C++ online submissions for Validate Binary Search Tree.

class Solution {
public:
	bool reS(TreeNode* root, long iMin, long iMax) {
		if (root == NULL) { return true; }
		if (root->val <= iMin || root->val >= iMax) { return false; }
		return reS(root->left, iMin, root->val) && reS(root->right, root->val, iMax);
	}

	bool isValidBST(TreeNode* root) {
		if (root == NULL) { return true; }
		return reS(root->left, LONG_MIN, root->val) && reS(root->right, root->val, LONG_MAX);
	}
};