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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        TreeNode *left = root->left;
        TreeNode *right = root->right;

        flatten(root->left);
        flatten(root->right);

        if (left) {
            auto rMost = rightMost(left);
            root->right = left;
            rMost->right = right;
            root->left = NULL;
        }
    }

    TreeNode *rightMost(TreeNode *root) {
        while (root->right) {
            root = root->right;
        }

        return root;
    }
};
