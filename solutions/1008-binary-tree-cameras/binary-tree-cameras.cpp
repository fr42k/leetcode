// Given a binary tree, we install cameras on the nodes of the tree. 
//
// Each camera at a node can monitor its parent, itself, and its immediate children.
//
// Calculate the minimum number of cameras needed to monitor all nodes of the tree.
//
//  
//
// Example 1:
//
//
//
// Input: [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
//
//
//
// Example 2:
//
//
// Input: [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
//
//
//
// Note:
//
//
// 	The number of nodes in the given tree will be in the range [1, 1000].
// 	Every node has value 0.
//
//
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
    int minCameraCover(TreeNode* root) {
        dfs(root, nullptr);
        return ans;
    }
    int ans = 0;
    unordered_set<TreeNode*> cover;
    void dfs(TreeNode* cur, TreeNode* prev) {
        if (cur) {
            dfs(cur->left, cur);
            dfs(cur->right, cur);
            if (!prev && !cover.count(cur) ||
               cur->left && !cover.count(cur->left) ||
               cur->right && !cover.count(cur->right)) {
                ++ans;
                cover.emplace(cur);
                if (prev) cover.emplace(prev);
                if (cur->left) cover.emplace(cur->left);
                if (cur->right) cover.emplace(cur->right);
            }
        }
    }
};
