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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->left) {
            root = rotate(root);
            return increasingBST(root);
        }

        root->right = increasingBST(root->right);
        return root;
    }

    TreeNode* rotate(TreeNode *root) {
        if (root == NULL || root->left == NULL) {
            return root;
        }

        auto left = root->left;
        root->left = left->right;
        left->right = root;
        return left;
    }
};
