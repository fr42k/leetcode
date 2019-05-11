// Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.
//
//
// Example:
//
// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13
//
// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> tree_stack;
        vector<int> tmp_v;
        first_travel(root, &tree_stack);
        auto tmp_s(tree_stack);
        int sum = 0;
        while (!tmp_s.empty()) {
            int k = tmp_s.top()->val;
            sum += k;
            tmp_v.emplace_back(sum);
            tmp_s.pop();
        }
        for (int i = 0; i < tmp_v.size(); i++) {
            TreeNode* r = tree_stack.top();
            r->val = tmp_v[i];
            tree_stack.pop();
        }
        return root;
    }
private:
    void first_travel(TreeNode* root, stack<TreeNode*>* tree_stack) {
        if (root == nullptr) {
            return;
        }
        first_travel(root->left, tree_stack);
        tree_stack->emplace(root);
        first_travel(root->right, tree_stack);
    }
};
