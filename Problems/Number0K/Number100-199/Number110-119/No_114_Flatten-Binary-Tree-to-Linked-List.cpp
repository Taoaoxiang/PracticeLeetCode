//Given a binary tree, flatten it to a linked list in-place.
//
//For example, given the following tree:
//
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//
//The flattened tree should look like:
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6
//
//

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage : 9.7 MB, less than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.

class Solution {
public:
	void flatten(TreeNode* root) {
		while (root != NULL) {
			if (root->left == NULL && root->right == NULL) { break; }
			else if (root->left != NULL && root->right == NULL) {
				root->right = root->left;
				root->left = NULL;
			}
			else if (root->left == NULL && root->right != NULL) {}
			else {
				TreeNode* tR = root->left;
				while (tR->right != NULL) { tR = tR->right; }
				tR->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
			root = root->right;
		}
		return;
	}
};


//Runtime: 12 ms, faster than 44.76% of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage : 9.7 MB, less than 100.00% of C++ online submissions for Flatten Binary Tree to Linked List.

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) { return; }
		stack<TreeNode*> sTrees;
		sTrees.push(root);
		while (sTrees.size() > 0) {
			TreeNode* ro = sTrees.top();
			sTrees.pop();
			if (ro->left == NULL && ro->right == NULL) {
				if (sTrees.size() > 0) { ro->right = sTrees.top(); }
				continue;
			}
			else if (ro->left != NULL && ro->right == NULL) {
				ro->right = ro->left;
				ro->left = NULL;
				sTrees.push(ro->right);
			}
			else if (ro->left == NULL && ro->right != NULL) {
				sTrees.push(ro->right);
			}
			else {
				sTrees.push(ro->right);
				ro->right = ro->left;
				ro->left = NULL;
				sTrees.push(ro->right);
			}
		}
		return;
	}
};