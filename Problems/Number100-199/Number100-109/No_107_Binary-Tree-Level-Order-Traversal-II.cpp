//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
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
//return its bottom - up level order traversal as :
//
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]


//Runtime: 16 ms, faster than 36.01% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage : 15.6 MB, less than 5.03% of C++ online submissions for Binary Tree Level Order Traversal II.

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
				rtn.insert(rtn.begin(), vTemp);
				qTree = qTemp;
			}
		}

		return rtn;
	}
};