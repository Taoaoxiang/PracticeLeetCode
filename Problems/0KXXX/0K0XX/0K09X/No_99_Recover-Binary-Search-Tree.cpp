//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Example 1:
//
//Input: [1, 3, null, null, 2]
//
//	1
//	/
//	3
//	\
//	2
//
//	Output: [3, 1, null, null, 2]
//
//	3
//	/
//	1
//	\
//	2
//
//	Example 2:
//
//   Input: [3, 1, 4, null, null, 2]
//
//	   3
//	   / \
//	   1   4
//	   /
//	   2
//
//	   Output: [2, 1, 4, null, null, 3]
//
//	   2
//	   / \
//	   1   4
//	   /
//	   3
//
//	   Follow up :
//
//		  A solution using O(n) space is pretty straight forward.
//			  Could you devise a constant space solution ?
//


//Runtime: 32 ms, faster than 97.43% of C++ online submissions for Recover Binary Search Tree.
//Memory Usage : 17.6 MB, less than 99.22% of C++ online submissions for Recover Binary Search Tree.

class Solution {
public:
	void recoverTree(TreeNode* root) {

		TreeNode* cur = root, *pre;
		TreeNode* v1 = NULL, *v2 = NULL, *comp = NULL;
		while (cur != NULL) {
			if (comp != NULL && comp->val >= cur->val) {
				if (v1 == NULL) { v1 = comp; }
				v2 = cur;
			}

			if (cur->left == NULL) {
				comp = cur;
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
					comp = cur;
					cur = cur->right;
				}
			}
		}
		int temp = v1->val;
		v1->val = v2->val;
		v2->val = temp;

		return;
	}
};

//Runtime: 32 ms, faster than 97.43% of C++ online submissions for Recover Binary Search Tree.
//Memory Usage : 19.2 MB, less than 91.41% of C++ online submissions for Recover Binary Search Tree.

// Using stack
class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode* cur = root, *pre;
		TreeNode* v1 = NULL, *v2 = NULL, *comp = NULL;

		stack<TreeNode*> sTree;
		while (sTree.size() > 0 || cur != NULL) {
			while (cur != NULL) {
				sTree.push(cur);
				cur = cur->left;
			}
			cur = sTree.top();
			if (comp != NULL && comp->val >= cur->val) {
				if (v1 == NULL) { v1 = comp; }
				v2 = cur;
			}
			comp = cur;
			sTree.pop();
			cur = cur->right;
		}
		int temp = v1->val;
		v1->val = v2->val;
		v2->val = temp;

		return;
	}
};