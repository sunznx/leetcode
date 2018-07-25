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
    TreeNode *prev;

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        
        bool res = isValidBST(root->left);
        if (res == false) {
            return false;
        }
        
        if (prev) {
            if (prev->val >= root->val) {
                return false;
            }
        }
        
        prev = root;
        
        return isValidBST(root->right);
    }
};
