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

    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        diameterOfBinaryTreeHelp(root);
        return res;
    }

    int diameterOfBinaryTreeHelp(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int l = diameterOfBinaryTreeHelp(root->left);
        int r = diameterOfBinaryTreeHelp(root->right);

        res = max(res, l+r);
        return max(l, r) + 1;
    }
};
