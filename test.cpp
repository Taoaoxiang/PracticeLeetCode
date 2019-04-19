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
	int pos = 0;
	TreeNode* reBuild(vector<int>& preorder, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& mp) {
		if (iStart > iEnd) { return NULL; }
		TreeNode* root = new TreeNode(preorder[pos]);
		++pos;
		if (iStart == iEnd) { return root; }
		int inPos = mp[root->val];
		//int inPos = find(inorder.begin()+iStart, inorder.begin()+iEnd, root->val) -inorder.begin();
		//cout << "T0: pos=>" << pos << " iStart=>"  << iStart << ", inPos=>" <<inPos  << endl;
		root->left = reBuild(preorder, inorder, iStart, inPos-1, mp);
		root->right = reBuild(preorder, inorder, inPos + 1, iEnd, mp);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) { return NULL; }
		else if (preorder.size() == 1) { return new TreeNode(preorder[0]); }
		else {
			unordered_map<int, int> mp;
			for (int i = 0; i < inorder.size();++i) { mp[inorder[i]] = i; }
			TreeNode* root = reBuild(preorder, inorder, 0, preorder.size()-1, mp);
			return root;
		}
	}
};








int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}