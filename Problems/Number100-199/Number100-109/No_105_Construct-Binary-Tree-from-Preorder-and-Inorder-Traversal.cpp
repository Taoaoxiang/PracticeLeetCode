//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3, 9, 20, 15, 7]
//inorder = [9, 3, 15, 20, 7]
//
//Return the following binary tree :
//
//3
/// \
//9  20
/// \
//15   7
//

//Runtime: 24 ms, faster than 79.73% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage : 17 MB, less than 39.45% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

// Using recursion and unordered_map
class Solution {
public:
	int pos = 0;
	TreeNode* reBuild(vector<int>& preorder, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& mp) {
		if (iStart > iEnd) { return NULL; }
		TreeNode* root = new TreeNode(preorder[pos]);
		++pos;
		if (iStart == iEnd) { return root; }
		int inPos = mp[root->val];
		//cout << "T0: pos=>" << pos << " iStart=>"  << iStart << ", inPos=>" <<inPos  << endl;
		root->left = reBuild(preorder, inorder, iStart, inPos - 1, mp);
		root->right = reBuild(preorder, inorder, inPos + 1, iEnd, mp);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) { return NULL; }
		else if (preorder.size() == 1) { return new TreeNode(preorder[0]); }
		else {
			unordered_map<int, int> mp;
			for (int i = 0; i < inorder.size();++i) { mp[inorder[i]] = i; }
			TreeNode* root = reBuild(preorder, inorder, 0, preorder.size() - 1, mp);
			return root;
		}
	}
};



//Runtime: 20 ms, faster than 89.12% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
//Memory Usage : 19.4 MB, less than 19.03% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.

// Recursive version
class Solution {
public:
	int pos = 0;
	TreeNode* reBuild(vector<int>& preorder, vector<int>& inorder, int iStart, int iEnd) {
		if (iStart > iEnd) { return NULL; }
		TreeNode* root = new TreeNode(preorder[pos]);
		++pos;
		if (iStart == iEnd) { return root; }
		int inPos = find(inorder.begin() + iStart, inorder.begin() + iEnd, root->val) - inorder.begin();
		//cout << "T0: pos=>" << pos << " iStart=>"  << iStart << ", inPos=>" <<inPos  << endl;
		root->left = reBuild(preorder, inorder, iStart, inPos - 1);
		root->right = reBuild(preorder, inorder, inPos + 1, iEnd);
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) { return NULL; }
		else if (preorder.size() == 1) { return new TreeNode(preorder[0]); }
		else {
			TreeNode* root = reBuild(preorder, inorder, 0, preorder.size() - 1);
			return root;
		}
	}
};
