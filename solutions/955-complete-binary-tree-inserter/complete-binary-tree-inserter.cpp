// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
//
// Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:
//
//
// 	CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
// 	CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
// 	CBTInserter.get_root() will return the head node of the tree.
//
//
//
//
//
//
//  
//
// Example 1:
//
//
// Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
// Output: [null,1,[1,2]]
//
//
//
// Example 2:
//
//
// Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
// Output: [null,3,4,[1,2,3,4,5,6,7,8]]
//
//
//
//  
//
// Note:
//
//
// 	The initial given tree is complete and contains between 1 and 1000 nodes.
// 	CBTInserter.insert is called at most 10000 times per test case.
// 	Every value of a given or inserted node is between 0 and 5000.
//
//
//
//
//
//  
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        r = root;
        q.emplace(r);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left && p->right) {
                q.emplace(p->left);
                q.emplace(p->right);
            } else {
                last = p;
                if (p->left) {
                    q.emplace(p->left);
                }
                break;
            }
        }
    }
    
    int insert(int v) {
        if (!last->left) {
            last->left = new TreeNode(v);
            q.emplace(last->left);
            return last->val;
        } else {
            last->right = new TreeNode(v);
            int ans = last->val;
            q.emplace(last->right);
            last = q.front();
            q.pop();
            return ans;
        }
    }
    
    TreeNode* get_root() {
        return r;
    }
    TreeNode* r;
    TreeNode* last;
    queue<TreeNode*> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
