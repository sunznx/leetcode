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
        postOrder(root);
        return res;
    }
    
    int postOrder(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int l = postOrder(root->left);
        int r = postOrder(root->right);
        res = max(res, l+r);
        return max(l, r) + 1;
    }
};
