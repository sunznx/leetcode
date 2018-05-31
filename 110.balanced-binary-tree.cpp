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
    int height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        if (root->left && root->right) {
            return max(height(root->left), height(root->right)) + 1;
        }

        if (root->left) {
            return height(root->left) + 1;
        }

        if (root->right) {
            return height(root->right) + 1;
        }

        return 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int h1 = height(root->left);
        int h2 = height(root->right);

        if (h1 - h2 > 1 || h2 - h1 > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);

    }
};
