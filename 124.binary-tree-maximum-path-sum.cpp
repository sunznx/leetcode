// CreateTime: 2019-12-11 17:03:20
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
    int ans;

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        pathSum(root);
        return ans;
    }

    int pathSum(TreeNode *root) {
        auto l = 0;
        auto r = 0;
        if (root->left) {
            l = pathSum(root->left);
        }
        if (root->right) {
            r = pathSum(root->right);
        }

        ans = max(ans, root->val);
        ans = max(ans, root->val + l);
        ans = max(ans, root->val + r);
        ans = max(ans, root->val + l + r);

        int ret = root->val;
        ret = max(ret, root->val + l);
        ret = max(ret, root->val + r);
        return ret;
    }
};
