#include "include_LeetCode.h"


class Solution {
public:
	int sum;
	int reS(TreeNode* root) {
		if (root == NULL) { return 0; }
		int iL = max(0, reS(root->left));
		int iR = max(0, reS(root->right));
		sum = max(sum, iL+iR+root->val);
		return (max(iL, iR) + root->val);
	}

	int maxPathSum(TreeNode* root) {
		sum = INT_MIN;
		reS(root);
		return sum;
	}
};





int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}