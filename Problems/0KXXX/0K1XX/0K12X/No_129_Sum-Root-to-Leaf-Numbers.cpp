//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Input: [1,2,3]
//    1
//   / \
//  2   3
//Output: 25
//Explanation:
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//Therefore, sum = 12 + 13 = 25.
//
//Example 2:
//
//Input: [4,9,0,5,1]
//    4
//   / \
//  9   0
// / \
//5   1
//Output: 1026
//Explanation:
//The root-to-leaf path 4->9->5 represents the number 495.
//The root-to-leaf path 4->9->1 represents the number 491.
//The root-to-leaf path 4->0 represents the number 40.
//Therefore, sum = 495 + 491 + 40 = 1026.
//

//Runtime: 12 ms, faster than 19.92% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage : 12.5 MB, less than 42.68% of C++ online submissions for Sum Root to Leaf Numbers.

// Short and slower? Again? LOL :P
class Solution {
public:
	int reS(TreeNode* root, int n) {
		if (root == NULL) { return 0; }
		n = n * 10 + root->val;
		if (root->left == NULL && root->right == NULL) { return n; }
		else { return reS(root->left, n) + reS(root->right, n); }
	}
	int sumNumbers(TreeNode* root) {
		return reS(root, 0);
	}
};

//Runtime: 8 ms, faster than 81.08% of C++ online submissions for Sum Root to Leaf Numbers.
//Memory Usage : 12.8 MB, less than 15.29% of C++ online submissions for Sum Root to Leaf Numbers.

class Solution {
public:
	void reS(TreeNode* root, int n, int& rtn) {
		if (root->left == NULL && root->right == NULL) {
			rtn += (n + root->val);
		}
		else if (root->left != NULL && root->right == NULL) {
			reS(root->left, 10 * (n + root->val), rtn);
		}
		else if (root->left == NULL && root->right != NULL) {
			reS(root->right, 10 * (n + root->val), rtn);
		}
		else {
			reS(root->left, 10 * (n + root->val), rtn);
			reS(root->right, 10 * (n + root->val), rtn);
		}
		return;
	}
	int sumNumbers(TreeNode * root) {
		if (root == NULL) { return 0; }
		int rtn = 0;
		reS(root, 0, rtn);
		return rtn;
	}
};