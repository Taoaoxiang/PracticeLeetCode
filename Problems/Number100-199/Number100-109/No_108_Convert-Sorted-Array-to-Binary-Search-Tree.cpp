//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//0
/// \
//- 3   9
///   /
//-10  5
//



//Runtime: 24 ms, faster than 85.59% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
//Memory Usage : 21 MB, less than 86.35% of C++ online submissions for Convert Sorted Array to Binary Search Tree.

// Recursive version
class Solution {
public:
	TreeNode* reSearch(int iStart, int iEnd, vector<int>& nums) {
		//cout <<"iStart=>" << iStart <<", iEnd=>" <<iEnd<<endl;
		if (iStart > iEnd) { return NULL; }
		int iM = (iStart + iEnd) / 2;
		TreeNode* root = new TreeNode(nums[iM]);
		if (iStart == iEnd) { return root; }
		root->left = reSearch(iStart, iM - 1, nums);
		root->right = reSearch(iM + 1, iEnd, nums);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) { return NULL; }
		TreeNode* root = reSearch(0, nums.size() - 1, nums);
		return root;
	}
};