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

        bool res1 = isValidBST(root->left);
        if (res1 == false) {
            return false;
        }

        if (prev) {
            if (prev->val >= root->val) {
                return false;
            }
        }
        prev = root;

        bool res2 = isValidBST(root->right);
        return res2;
    }
};
