//Runtime: 8 ms, faster than 21.71% of C++ online submissions for Binary Tree Postorder Traversal.
//Memory Usage : 9.3 MB, less than 42.21% of C++ online submissions for Binary Tree Postorder Traversal.

// Stack version
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> rtn;
		stack<TreeNode*> sTrees;
		sTrees.push(root);
		while (!sTrees.empty()) {
			TreeNode* r = sTrees.top();
			sTrees.pop();
			if (r == NULL) { continue; }
			else {
				rtn.insert(rtn.begin(), r->val);
				sTrees.push(r->left);
				sTrees.push(r->right);
			}
		}
		return rtn;
	}
};


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
//Memory Usage : 9.5 MB, less than 11.05% of C++ online submissions for Binary Tree Postorder Traversal.

// Recursive method
class Solution {
public:
	void rePre(TreeNode* root, vector<int>& rtn) {
		if (root == NULL) { return; }
		rePre(root->left, rtn);
		rePre(root->right, rtn);
		rtn.push_back(root->val);
		return;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> rtn;
		rePre(root, rtn);
		return rtn;
	}
};