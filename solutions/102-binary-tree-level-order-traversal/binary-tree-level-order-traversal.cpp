// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its level order traversal as:
//
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.emplace(root);
        q.emplace(nullptr);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p) {
                level.emplace_back(p->val);
                if (p->left) q.emplace(p->left);
                if (p->right) q.emplace(p->right);
            } else {
                ans.emplace_back(level);
                level.clear();
                if (!q.empty()) q.emplace(p);
            }
        }
        return ans;
    }
};