// Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.
//
// (A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)
//
//  
//
// Example 1:
//
//
//
//
// Input: [8,3,10,1,6,null,14,null,null,4,7,13]
// Output: 7
// Explanation: 
// We have various ancestor-node differences, some of which are given below :
// |8 - 3| = 5
// |3 - 7| = 4
// |8 - 1| = 7
// |10 - 13| = 3
// Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
//
//
//  
//
// Note:
//
//
// 	The number of nodes in the tree is between 2 and 5000.
// 	Each node will have value between 0 and 100000.
//
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
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        int imin = INT_MAX, imax = INT_MIN;
        preorder(root, ans, imin, imax);
        return ans;
    }
    void preorder(TreeNode* root, int& ans, int imin, int imax) {
        if (!root) return;
        imin = min(root->val, imin);
        imax = max(root->val, imax);
        ans = max(ans, (imax - imin));
        preorder(root->left, ans, imin, imax);
        preorder(root->right, ans, imin, imax);
    }
};
