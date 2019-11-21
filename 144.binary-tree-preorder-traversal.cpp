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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        f(res, root);
        return res;
    }

    void f(vector<int> &res, TreeNode *root) {
        if (root == NULL) {
            return;
        }

        res.push_back(root->val);
        f(res, root->left);
        f(res, root->right);
    }
};
