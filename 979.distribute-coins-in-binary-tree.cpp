// CreateTime: 2019-11-22 14:01:13
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

    int distributeCoins(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        traversal(root->left);
        traversal(root->right);

        int v;
        if (root->left) {
            v = root->left->val-1;
            root->left->val = 1;
            root->val += v;
            res += abs(v);
        }
        if (root->right) {
            v = root->right->val-1;
            root->right->val = 1;
            root->val += v;
            res += abs(v);
        }
    }
};
