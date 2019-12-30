// CreateTime: 2019-12-30 19:23:07
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
    const int MOD = 1e9+7;
    int res = 0;

    int sumRootToLeaf(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode *root, int v = 0) {
        if (root == NULL) {
            return;
        }

        v = v * 2 + root->val;
        
        if (root->left == NULL && root->right == NULL) {
            res = ((long long)res + (long long)v) % MOD;
            return;
        }

        dfs(root->left, v);
        dfs(root->right, v);
    }
};
