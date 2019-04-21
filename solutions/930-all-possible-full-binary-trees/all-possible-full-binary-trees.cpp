// A full binary tree is a binary tree where each node has exactly 0 or 2 children.
//
// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.
//
// Each node of each tree in the answer must have node.val = 0.
//
// You may return the final list of trees in any order.
//
//  
//
// Example 1:
//
//
// Input: 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
// Explanation:
//
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 20
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (!mem.count(N)) {
            if (N < 1 || N % 2 == 0) return {};
            if (N == 1) return vector<TreeNode*>{new TreeNode(0)};
            vector<TreeNode*> ans;
            for (int i = 1; i < N; i += 2) {
                auto l = allPossibleFBT(i);
                auto r = allPossibleFBT(N - i - 1);
                for (auto left: l) {
                    for (auto right: r) {
                        auto cur = new TreeNode(0);
                        cur->left = left;
                        cur->right = right;
                        ans.emplace_back(cur);
                    }
                }
            }
            mem[N] = ans;
            
        }
        return mem[N];
    }
    unordered_map<int, vector<TreeNode*>> mem;
};
