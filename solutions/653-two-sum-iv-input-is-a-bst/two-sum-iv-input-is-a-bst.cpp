// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False
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
    bool findTarget(TreeNode* root, int k) {
        if (!root) {
            return false;
        }
        vector<int> st{};
        visit(root, &st);
        for (int i = 0, j = st.size() - 1; i < j;) {
            if (st[i] + st[j] == k) {
                return true;
            } else if (st[i] + st[j] < k) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
    void visit(TreeNode* root, vector<int>* st) {
        if (!root) {
            return;
        }
        visit(root->left, st);
        st->emplace_back(root->val);
        visit(root->right, st);
    }
};
