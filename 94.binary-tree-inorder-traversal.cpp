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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        f(res, root);
        return res;
    }
    
    void f(vector<int> &res, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        f(res, root->left);
        res.push_back(root->val);
        f(res, root->right);
    }
};
