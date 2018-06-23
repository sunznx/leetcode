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
    TreeNode *prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        if (root->left) {
            auto res = isValidBST(root->left);
            if (res == false) {
                return false;
            }
        }

        if (prev) {
            if (root->val <= prev->val) {
                return false;
            }
        }

        prev = root;

        if (root->right) {
            auto res = isValidBST(root->right);
            if (res == false) {
                return false;
            }
        }

        return true;
    }
};
