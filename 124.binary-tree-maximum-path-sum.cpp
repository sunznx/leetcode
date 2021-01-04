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
        auto l = 0;
        auto r = 0;

        if (root->left) {
            l = helper(root->left);
        }

        if (root->right) {
            r = helper(root->right);
        }

        ans = max(ans, root->val);
        ans = max(ans, root->val+l);
        ans = max(ans, root->val+r);
        ans = max(ans, root->val+l+r);

        int ret = root->val;
        ret = max(ret, root->val+l);
        ret = max(ret, root->val+r);
        return ret;
    }
};
