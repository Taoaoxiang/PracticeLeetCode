#include "include_LeetCode.h"


//
//class Solution {
//public:
//	int candy(vector<int>& ratings) {
//		int nums = ratings.size();
//		if ( nums == 0) { return 0; }
//		else if (nums == 1) { return 1; }
//		else if (nums == 2) {
//			if (ratings[0] == ratings[1]) { return 2; }
//			else { return 3; }
//		}
//		else {
//			int rtn = 0;
//
//
//
//			sort(ratings.begin(), ratings.end());
//			int iLast = INT_MIN;
//			int iCandy = 0;
//			for (int i = 0; i < nums; ++i) {
//				if (ratings[i] > iLast) {
//					++iCandy;
//					iLast = ratings[i];
//				}
//				else {
//					if (iCandy - 1 > 0) { --iCandy; }
//				}
//				rtn += iCandy;
//			}
//			return rtn;
//		}
//	}
//};




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


int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}