//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//
//return its level order traversal as :
//
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]


//Runtime: 12 ms, faster than 48.80% of C++ online submissions for Binary Tree Level Order Traversal.
//Memory Usage : 15.5 MB, less than 6.44% of C++ online submissions for Binary Tree Level Order Traversal.

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> rtn;
		queue<TreeNode*> qTree;
		TreeNode* t = NULL;
		qTree.push(root);
		while (qTree.size() > 0) {
			queue<TreeNode*> qTemp;
			vector<int> vTemp;
			while (qTree.size() > 0) {
				t = qTree.front();
				qTree.pop();
				if (t == NULL) { continue; }
				else {
					vTemp.push_back(t->val);
					qTemp.push(t->left);
					qTemp.push(t->right);
				}
			}
			if (vTemp.size() > 0) {
				rtn.push_back(vTemp);
				qTree = qTemp;
			}
		}

		return rtn;
	}
};