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
    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }

    int maxDepth(TreeNode* root, int res) {
        if (root == NULL) {
            return res;
        }

        return max(maxDepth(root->left, res+1), maxDepth(root->right, res+1));
    }
};
