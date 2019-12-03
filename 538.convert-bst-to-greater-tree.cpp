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
    TreeNode* convertBST(TreeNode* root) {
        int x = 0;
        return convertBST(root, x);
    }

    TreeNode* convertBST(TreeNode* root, int &x) {
        if (root == NULL) {
            return root;
        }

        if (root->right) {
            root->right = convertBST(root->right, x);
        }

        int pre = x;
        x += root->val;
        root->val += pre;

        if (root->left) {
            root->left = convertBST(root->left, x);
        }

        return root;
    }
};
