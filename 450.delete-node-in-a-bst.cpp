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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val == key) {
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            if (left == NULL && right == NULL) {
                return NULL;
            } else if (left == NULL) {
                return right;
            } else if (right == NULL) {
                return left;
            } else {
                auto maxT = findMax(root->left);
                root->val = maxT->val;
                root->left = deleteNode(root->left, root->val);
            }
        }

        return root;
    }

    TreeNode *findMax(TreeNode *root) {
        while (root->right) {
            root = root->right;
        }

        return root;
    }
};
