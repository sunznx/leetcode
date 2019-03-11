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
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int l = height(root->left);
        int r = height(root->right);
        
        if (abs(l-r) >= 2) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = height(root->left);
        int r = height(root->right);

        
        return max(l, r) + 1;
    }
};
