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
    void swap(TreeNode *&i, TreeNode *&j) {
        TreeNode *t = i;
        i = j;
        j = t;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        if (root->left == NULL && root->right == NULL) {
            return root;
        }

        swap(root->left, root->right);
        if (root->left) {
            root->left = invertTree(root->left);
        }
        if (root->right) {
            root->right = invertTree(root->right);
        }

        return root;
    }
};
