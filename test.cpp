#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <stack>
#include <queue>

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








int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}