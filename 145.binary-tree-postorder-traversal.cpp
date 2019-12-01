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
    vector<int> res;

    vector<int> postorderTraversal(TreeNode* root) {
        postorderTraversalHelp(root);
        return res;
    }

    void postorderTraversalHelp(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            postorderTraversalHelp(root->left);
        }
        if (root->right) {
            postorderTraversalHelp(root->right);
        }

        res.push_back(root->val);
    }
};
