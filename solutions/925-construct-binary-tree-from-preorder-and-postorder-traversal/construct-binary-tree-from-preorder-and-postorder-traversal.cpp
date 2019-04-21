// Return any binary tree that matches the given preorder and postorder traversals.
//
// Values in the traversals pre and post are distinct positive integers.
//
//  
//
//
// Example 1:
//
//
// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
//
//
//  
//
// Note:
//
//
// 	1 <= pre.length == post.length <= 30
// 	pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// 	It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // vector<TreeNode*> s;
        // s.emplace_back(new TreeNode(pre[0]));
        // for (int i = 1, j = 0; i < pre.size(); i++) {
        //     while (s.back()->val == post[j]) {
        //         s.pop_back();
        //         j++;
        //     }
        //     auto cur = new TreeNode(pre[i]);
        //     if (s.back()->left == nullptr) {
        //         s.back()->left = cur;
        //     } else {
        //         s.back()->right = cur;
        //     }
        //     s.emplace_back(cur);
        // }
        // return s[0];
        unordered_map<int, int> pos;
        for (int i = 0; i < post.size(); i++) {
            pos[post[i]] = i;
        }
        return construct(pre, post, 0, pre.size() - 1, 0, post.size() - 1, pos);
    }
    TreeNode* construct(vector<int>& pre, vector<int>& post, int a, int b, int c, int d, unordered_map<int, int>& pos) {
        TreeNode* cur = new TreeNode(pre[a]);
        if (a == b) return cur;
        int leftroot = pre[a + 1];
        int idx = pos[leftroot];
        int len = idx - c + 1;
        cur->left = construct(pre, post, a + 1, a + len, c, c + len - 1, pos);
        if (idx + 1 == d) return cur;
        cur->right = construct(pre, post, a + len + 1, b, c + len, d - 1, pos);
        return cur;
    }
    
};
