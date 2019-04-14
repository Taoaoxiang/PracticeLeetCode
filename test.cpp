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



//class Solution {
//public:
//	vector<TreeNode*> generateTrees(int n) {
//		vector<TreeNode*> rtn;
//		for (int i = 1; i <= n; ++i) {
//			TreeNode root(i);
//			vector<int> tmp = {i};
//
//			reGen(root, i, i, n, tmp);
//			rtn.push_back(&root);
//		
//		}
//
//	}
//};




class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) { return false; }
		if (s3.size() == 0) { return true; }
		int pos1 = 0, pos2 = 0, pos3 = 0;
		stack<pair<int,int>> alt;
		while (pos3 < s3.size()) {
			if (s1[pos1] == s2[pos2] && s3[pos3] == s1[pos1]) {
				alt.push({ pos1, pos2 });
				++pos3;
				++pos1;
			}
			else if (s3[pos3] == s1[pos1]) {
				++pos3;
				++pos1;
			}
			else if (s3[pos3] == s2[pos2]) {
				++pos3;
				++pos2;
			}
			else if (!alt.empty()){
				pos2 = alt.top().second+1;
				pos1 = alt.top().first;
				alt.pop();
				pos3 = pos1 + pos2;
			}
			else { return false; }
		}
		return true;
	}
};
int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}