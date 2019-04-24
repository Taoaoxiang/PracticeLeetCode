//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//But the following[1, 2, 2, null, 3, null, 3] is not:
//
//1
/// \
//2   2
//\   \
//3    3
//
//Note:
//Bonus points if you could solve it both recursively and iteratively.

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
//Memory Usage : 14.9 MB, less than 99.46% of C++ online submissions for Symmetric Tree.

// Iterative version
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) { return true; }
		stack<TreeNode*> sTrees;
		TreeNode* t1 = NULL, *t2 = NULL;
		sTrees.push(root->left);
		sTrees.push(root->right);
		while (sTrees.size() > 0) {
			t1 = sTrees.top();
			sTrees.pop();
			t2 = sTrees.top();
			sTrees.pop();
			if (t1 == NULL && t2 == NULL) { continue; }
			else if (t1 == NULL || t2 == NULL) { return false; }
			else if (t1->val != t2->val) { return false; }
			else {
				sTrees.push(t1->left);
				sTrees.push(t2->right);
				sTrees.push(t1->right);
				sTrees.push(t2->left);
			}
		}
		return true;
	}
};

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
//Memory Usage : 14.7 MB, less than 99.82% of C++ online submissions for Symmetric Tree.

// Recursive version
class Solution {
public:
	bool reMatch(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL) { return true; }
		else if (t1 == NULL || t2 == NULL) { return false; }
		else if (t1->val != t2->val) { return false; }
		else { return reMatch(t1->left, t2->right) && reMatch(t1->right, t2->left); }
	}

	bool isSymmetric(TreeNode* root) {
		if (root == NULL) { return true; }
		return reMatch(root->left, root->right);
	}
};