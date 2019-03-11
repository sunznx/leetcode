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
    int res = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        
        return res;
    }
    
    int height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);
        
        int d = (l+r);
        res = max(d, res);
        
        return max(l, r) + 1;
    }
};
