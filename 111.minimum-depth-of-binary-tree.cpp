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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int count = 0;
        if (root->left && root->right) {
            count = min(minDepth(root->left), minDepth(root->right)) + 1;
        } else if (root->left) {
            count = minDepth(root->left) + 1;
        } else if (root->right) {
            count = minDepth(root->right) + 1;
        } else {
            count = 1;
        }
        return count;
    }
};
