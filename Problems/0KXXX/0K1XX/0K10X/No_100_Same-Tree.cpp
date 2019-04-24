//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
//
//Example 1:
//
//Input:     1         1
//	/ \ / \
//	2   3     2   3
//
//	[1, 2, 3], [1, 2, 3]
//
//	Output: true
//
//	Example 2 :
//
//	Input : 1         1
//	/ \
//	2             2
//
//	[1, 2], [1, null, 2]
//
//	Output: false
//
//	Example 3 :
//
//	Input : 1         1
//	/ \ / \
//	2   1     1   2
//
//	[1, 2, 1], [1, 1, 2]
//
//	Output: false
//
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Same Tree.
//Memory Usage : 9.8 MB, less than 99.45% of C++ online submissions for Same Tree.

class Solution {
public:
	bool reCheck(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL) { return true; }
		else if (p == NULL && q != NULL) { return false; }
		else if (p != NULL && q == NULL) { return false; }
		else {
			if (p->val == q->val) {
				if (reCheck(p->left, q->left) == false) { return false; }
				if (reCheck(p->right, q->right) == false) { return false; }
				return true;
			}
			else { return false; }
		}
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		return reCheck(p, q);
	}
};