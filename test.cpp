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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) { return NULL; }
		queue<TreeNode*> qTrees;
		queue<pair<int, int>> qPairs;
		int iM = (0 + nums.size()-1) / 2;
		TreeNode* root = new TreeNode(nums[iM]);
		qTrees.push(root);
		qPairs.push({0, iM -1});
		qPairs.push({iM+1, nums.size()-1});
		while (qTrees.size() > 0) {
			queue<TreeNode*> qTreesTemp;
			int mi = -1;
			while (qTrees.size() > 0) {
				TreeNode* ro = qTrees.front();
				qTrees.pop();
				pair<int, int> pL = qPairs.front();
				qPairs.pop();
				pair<int, int> pR = qPairs.front();
				qPairs.pop();
				if (pL.first <= pL.second) {
					mi = (pL.first + pL.second) / 2;
					ro->left = new TreeNode(nums[mi]);
					if (pL.first < pL.second) {
						qTreesTemp.push(ro->left);
						qPairs.push({ pL.first, mi-1});
						qPairs.push({ mi + 1, pL.second });
					}
				}
				if (pR.first <= pR.second) {
					mi = (pR.first + pR.second) / 2;
					ro->right = new TreeNode(nums[mi]);
					if (pR.first < pR.second) {
						qTreesTemp.push(ro->right);
						qPairs.push({ pR.first, mi - 1 });
						qPairs.push({ mi + 1, pR.second });
					}
				}
			}
			qTrees = qTreesTemp;
		}

		return root;
	}
};



int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}