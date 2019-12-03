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
    int res;

    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        res = 0;
        longestUnivaluePathHelp(root);
        return res;
    }

    int longestUnivaluePathHelp(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int l = 0;
        int r = 0;

        if (root->left) {
            l = longestUnivaluePathHelp(root->left);
            if (root->left->val == root->val) {
                l = l + 1;
            } else {
                l = 0;
            }
        }

        if (root->right) {
            r = longestUnivaluePathHelp(root->right);
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
