//Given a binary tree, return the preorder traversal of its nodes' values.
//
//Example:
//
//Input: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//Output: [1,2,3]
//
//Follow up: Recursive solution is trivial, could you do it iteratively?

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
//Memory Usage : 9.2 MB, less than 70.16% of C++ online submissions for Binary Tree Preorder Traversal.

// Morrise traversal
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> rtn;
		TreeNode* cur = root, * pre;
		while (cur != NULL) {
			pre = cur->left;
			if (pre == NULL) {
				rtn.push_back(cur->val);
				cur = cur->right;
			}
			else {
				while (pre->right != NULL && pre->right != cur) { pre = pre->right; }
				if (pre->right == NULL) {
					pre->right = cur;
					rtn.push_back(cur->val);
					cur = cur->left;
				}
				else if (pre->right == cur) {
					pre->right = NULL;
					cur = cur->right;
				}
			}
		}
		return rtn;
	}
};


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
//Memory Usage : 9.3 MB, less than 50.57% of C++ online submissions for Binary Tree Preorder Traversal.

// Stack version
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> rtn;
		stack<TreeNode*> sTrees;
		sTrees.push(root);
		while (!sTrees.empty()) {
			TreeNode* r = sTrees.top();
			sTrees.pop();
			if (r == NULL) { continue; }
			else {
				rtn.push_back(r->val);
				sTrees.push(r->right);
				sTrees.push(r->left);
			}
		}
		return rtn;
	}
};


//Runtime: 8 ms, faster than 21.74% of C++ online submissions for Binary Tree Preorder Traversal.
//Memory Usage : 9.4 MB, less than 27.11% of C++ online submissions for Binary Tree Preorder Traversal.

// Recursive solution
class Solution {
public:
	void rePre(TreeNode* root, vector<int>& rtn) {
		if (root == NULL) { return; }
		rtn.push_back(root->val);
		rePre(root->left, rtn);
		rePre(root->right, rtn);
		return;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> rtn;
		rePre(root, rtn);
		return rtn;
	}
};