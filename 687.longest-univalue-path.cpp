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
    int res = 0;

    int longestUnivaluePath(TreeNode* root) {
        travesal(root);

        return res;
    }

    int travesal(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int l = 0;
        int r = 0;
        if (root->left) {
            l = travesal(root->left);
            if (root->left->val == root->val) {
                l = l + 1;
            } else {
                l = 0;
            }
        }

        if (root->right) {
            r = travesal(root->right);
            if (root->right->val == root->val) {
                r = r + 1;
            } else {
                r = 0;
            }
        }

        res = max(res, l+r);

        return max(l, r);
    }
};
