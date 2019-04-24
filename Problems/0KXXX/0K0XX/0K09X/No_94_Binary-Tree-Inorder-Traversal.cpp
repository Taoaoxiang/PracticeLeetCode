//Given a binary tree, return the inorder traversal of its nodes' values.
//
//Example:
//
//Input: [1, null, 2, 3]
//	1
//	\
//	2
//	/
//	3
//
//	Output: [1, 3, 2]
//
//	Follow up : Recursive solution is trivial, could you do it iteratively ?
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage : 9 MB, less than 96.06% of C++ online submissions for Binary Tree Inorder Traversal.

// Use Morris Traversal Method
// One extra pointer as predecessor to proceed
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> rtn;
		TreeNode* cur = root, *pre;
		while (cur != NULL) {
			if (cur->left == NULL) {
				rtn.push_back(cur->val);
				cur = cur->right;
			}
			else {
				pre = cur->left;
				while (pre->right != NULL && pre->right != cur) { pre = pre->right; }
				if (pre->right == NULL) {
					pre->right = cur;
					cur = cur->left;
				}
				else if (pre->right == cur) {
					pre->right = NULL;
					rtn.push_back(cur->val);
					cur = cur->right;
				}
			}
		}
		return rtn;
	}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage : 9 MB, less than 96.20% of C++ online submissions for Binary Tree Inorder Traversal.

// Using stack, and no recursion
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> rtn;
		TreeNode* cur = root;
		stack<TreeNode*> sTree;
		while (sTree.size() > 0 || cur != NULL) {
			while (cur != NULL) {
				sTree.push(cur);
				cur = cur->left;
			}
			cur = sTree.top();
			sTree.pop();
			rtn.push_back(cur->val);
			cur = cur->right;
		}
		return rtn;
	}
};


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
//Memory Usage : 9.4 MB, less than 30.51% of C++ online submissions for Binary Tree Inorder Traversal.

// This is the recursive version
class Solution {
public:
	void re(TreeNode* root, vector<int>& rtn) {
		if (root->left != NULL) { re(root->left, rtn); }
		rtn.push_back(root->val);
		if (root->right != NULL) { re(root->right, rtn); }
		return;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL) { return {}; }
		vector<int> rtn;
		re(root, rtn);
		return rtn;
	}
};