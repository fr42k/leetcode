// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.emplace(root);
        q.emplace(nullptr);
        vector<int> tmp;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p) {
                tmp.emplace_back(p->val);
                if (p->left) q.emplace(p->left);
                if (p->right) q.emplace(p->right);
            } else {
                if (ans.size() & 1) {
                    ans.emplace_back(tmp.rbegin(), tmp.rend());
                } else {
                    ans.emplace_back(tmp);
                }
                tmp.clear();
                if (!q.empty()) q.emplace(p);
            }
        }
        return ans;
        */
        vector<vector<int>> ans;
        travel(root, 0, ans);
        return ans;
    }
    void travel(TreeNode* root, int level, vector<vector<int>>& ans) {
        if (!root) return;
        if (level >= ans.size()) ans.emplace_back(vector<int>());
        if (level & 1) ans[level].insert(ans[level].begin(), root->val);
        else ans[level].emplace_back(root->val);
        travel(root->left, level + 1, ans);
        travel(root->right, level + 1, ans);
    }
};
