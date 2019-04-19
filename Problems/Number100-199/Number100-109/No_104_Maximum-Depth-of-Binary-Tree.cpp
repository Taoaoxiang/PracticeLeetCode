//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	3
//	/ \
//	9  20
//	/ \
//	15   7
//
//	return its depth = 3.


//Runtime: 16 ms, faster than 99.07% of C++ online submissions for Maximum Depth of Binary Tree.
//Memory Usage : 22.7 MB, less than 5.45% of C++ online submissions for Maximum Depth of Binary Tree.

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int rtn = 0;
		queue<TreeNode*> qTree;
		TreeNode* t = NULL;
		qTree.push(root);
		while (qTree.size() > 0) {
			queue<TreeNode*> qTemp;
			while (qTree.size() > 0) {
				t = qTree.front();
				qTree.pop();
				if (t == NULL) { continue; }
				else {
					qTemp.push(t->left);
					qTemp.push(t->right);
				}
			}
			++rtn;
			qTree = qTemp;
		}

		return (rtn - 1);
	}
};