#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>
#include <stack>

using namespace std;
//
//class Solution {
//public:
//	int numDecodings(string s) {
//		
//		int sSize = s.size();
//		if (sSize == 0) { return 0; }
//		else if (sSize == 1) { 
//			if (s[0] == '0') { return 0; } 
//			else { return 1; }
//		}
//		int rtn = 0;
//		for (int i = 0; i < sSize; ++i) {
//			if (i == 0) {
//				if (s[i] == '0') { return 0; }
//				else if (s[i] == '1') { rtn += 2; }
//				else if (s[i] == '2') { 
//					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 2; }
//					else { rtn += 1; }
//				}
//				else { rtn += 1; }
//			}
//			else if (i == sSize - 1) {
//				if (s[i] == '0') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					else { return 0; }
//				}
//				else {
//					if (s[i - 1] == '1') { rtn += 2; }
//					else if (s[i - 1] == '2' && (s[i] >= '1'&&s[i] <= '6')) { rtn += 2; }
//					else { rtn += 1; }
//				}
//			}
//			else {
//				if (s[i] == '0') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					else { return 0; }
//				}
//				else if (s[i] == '1') { 
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 3; }
//					else { rtn += 2; }
//				}
//				else if (s[i] == '2') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 1; }
//					rtn += 1;
//				}
//				else { 
//					if (s[i - 1] == '1' ) { rtn += 2; } 
//					else if (s[i - 1] == '2' && (s[i]>='1'&&s[i] <= '6')) { rtn += 2; }
//					else { rtn += 1; }
//				}
//			}
//		}
//		return rtn-sSize-1;
//	}
//};
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:
	vector<TreeNode*> genTree(int iC, int n) {
		vector<TreeNode*> rtn;
		if (iC > n) { return { NULL }; }
		else if (iC == n) { return { new TreeNode(iC) }; }
		for (int i = iC; i <= n; ++i) {
			vector<TreeNode*> vecL = genTree(iC, i-1);
			vector<TreeNode*> vecR = genTree(i+1, n);
			for (int jL = 0; jL < vecL.size();++jL) {
				for (int jR = 0; jR < vecR.size();++jR) {
					TreeNode* tmp = new TreeNode(i);
					tmp->left = vecL[jL];
					tmp->right = vecR[jR];
					rtn.push_back(tmp);
				}
			}
		}
		return rtn;
	}

	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) { return {}; }
		return genTree(1, n);
	}
};





int main() {

	Solution().generateTrees(3);

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}