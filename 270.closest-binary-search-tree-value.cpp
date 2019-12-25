// CreateTime: 2019-12-25 14:50:39
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
    
    double d = -1;
    int ans = -1;

    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return ans;
    }
    
    void dfs(TreeNode* root, double target) {
        if (d < 0 || abs(target-root->val) < d) {
            d = abs(target-root->val);
            ans = root->val;
        }

        if (root->right && target > root->val) {
            dfs(root->right, target);
        }
        if (root->left && target < root->val) {
            dfs(root->left, target);
        }
    }
};
