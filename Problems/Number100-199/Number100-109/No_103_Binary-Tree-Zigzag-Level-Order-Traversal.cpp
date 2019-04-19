//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
//return its zigzag level order traversal as :
//
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]


//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
//Memory Usage : 14 MB, less than 16.44% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> rtn;
		queue<TreeNode*> qTree;
		int dir = 1;
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
			if (dir == -1) { reverse(vTemp.begin(), vTemp.end()); }
			if (vTemp.size() > 0) {
				rtn.push_back(vTemp);
				qTree = qTemp;
			}
			dir *= -1;
		}

		return rtn;
	}
};