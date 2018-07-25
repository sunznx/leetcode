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
    int res;
    TreeNode *prev;

    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        postOrder(root);
        return res;
    }
    
    int postOrder(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = postOrder(root->left);
        int r = postOrder(root->right);
        
        if (root->left && root->left->val == root->val) {
            l += 1;
        } else {
            l = 0;
        }
        
        if (root->right && root->right->val == root->val) {
            r += 1;
        } else {
            r = 0;
        }
        
        res = max(res, l+r);

        return max(l, r);
    }
};
