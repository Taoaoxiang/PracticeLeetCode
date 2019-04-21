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

//Runtime: 20 ms, faster than 100.00% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
//Memory Usage : 20.6 MB, less than 99.41% of C++ online submissions for Convert Sorted Array to Binary Search Tree.

// Not recursive version
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0) { return NULL; }
		queue<TreeNode*> qTrees;
		queue<pair<int, int>> qPairs;
		int iM = (0 + nums.size() - 1) / 2;
		TreeNode* root = new TreeNode(nums[iM]);
		qTrees.push(root);
		qPairs.push({ 0, iM - 1 });
		qPairs.push({ iM + 1, nums.size() - 1 });
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
						qPairs.push({ pL.first, mi - 1 });
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