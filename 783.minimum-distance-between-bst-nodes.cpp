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
    int res = INT_MAX;
    TreeNode *prev = NULL;

    int minDiffInBST(TreeNode* root) {
        traversal(root);
        return res;
    }

    void traversal(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            traversal(root->left);
        }

        if (prev) {
            res = min(res, root->val - prev->val);
        }
        prev = root;

        if (root->right) {
            traversal(root->right);
        }
    }
};
