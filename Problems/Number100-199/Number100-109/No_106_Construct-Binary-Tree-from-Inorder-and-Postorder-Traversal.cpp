//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9, 3, 15, 20, 7]
//postorder = [9, 15, 7, 20, 3]
//
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7
//


//Runtime: 24 ms, faster than 78.76% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage : 17.1 MB, less than 48.45% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.

// Recursive version
class Solution {
public:
	int pos = 0;
	TreeNode* reBuild(vector<int>& postorder, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& mp) {
		if (iStart > iEnd) { return NULL; }
		TreeNode* root = new TreeNode(postorder[pos]);
		--pos;
		if (iStart == iEnd) { return root; }
		int inPos = mp[root->val];
		root->right = reBuild(postorder, inorder, inPos + 1, iEnd, mp);
		root->left = reBuild(postorder, inorder, iStart, inPos - 1, mp);

		return root;
	}


	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) { return NULL; }
		else if (postorder.size() == 1) { return new TreeNode(postorder[0]); }
		else {
			unordered_map<int, int> mp;
			pos = postorder.size() - 1;
			for (int i = 0; i < inorder.size();++i) { mp[inorder[i]] = i; }
			TreeNode* root = reBuild(postorder, inorder, 0, postorder.size() - 1, mp);
			return root;
		}
	}
};


//Runtime: 64 ms, faster than 10.62% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
//Memory Usage : 60.3 MB, less than 13.67% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.

// My own solution, slow :)
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) { return NULL; }
		else if (postorder.size() == 1) { return new TreeNode(postorder[0]); }
		else {
			stack<vector<int>> sIn;
			stack<TreeNode*> sTrees;
			TreeNode* rtn = new TreeNode(postorder.back());
			sTrees.push(rtn);
			sIn.push(inorder);
			postorder.pop_back();
			while (sTrees.size() > 0) {
				TreeNode* root = sTrees.top();
				vector<int> subIn = sIn.top();
				sTrees.pop();
				sIn.pop();
				vector<int>::iterator it = find(subIn.begin(), subIn.end(), root->val);
				if (it == subIn.begin() && it == subIn.end() - 1) { continue; }
				else if (it == subIn.begin()) {
					root->right = new TreeNode(postorder.back());
					postorder.pop_back();
					sTrees.push(root->right);
					sIn.push(vector<int>(it + 1, subIn.end()));
				}
				else if (it + 1 == subIn.end()) {
					root->left = new TreeNode(postorder.back());
					postorder.pop_back();
					sTrees.push(root->left);
					sIn.push(vector<int>(subIn.begin(), it));
				}
				else {
					for (int i = postorder.size() - 1; i >= 0; --i) {
						if (find(subIn.begin(), it, postorder[i]) != it) {
							root->left = new TreeNode(postorder[i]);
							postorder.erase(postorder.begin() + i);
							break;
						}
					}
					sTrees.push(root->left);
					sIn.push(vector<int>(subIn.begin(), it));
					root->right = new TreeNode(postorder.back());
					postorder.pop_back();
					sTrees.push(root->right);
					sIn.push(vector<int>(it + 1, subIn.end()));
				}
			}

			return rtn;
		}
	}
};
