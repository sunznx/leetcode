// CreateTime: 2021-01-04 16:17:16
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;

    int maxPathSum(TreeNode *root) {
        helper(root);
        return ans;
    }

    int helper(TreeNode *root) {
        if (root == NULL) {
            return ans;
        }

        auto l = 0;
        auto r = 0;

        if (root->left) {
            l = helper(root->left);
            ans = max(ans, l);
            ans = max(ans, l + root->val);
        }

        if (root->right) {
            r = helper(root->right);
            ans = max(ans, r);
            ans = max(ans, r+root->val);
        }

        ans = max(ans, root->val);
        ans = max(ans, l+r+root->val);
        return max(root->val, max(l+root->val, r+root->val));
    }
};
