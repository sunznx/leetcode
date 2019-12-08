// CreateTime: 2019-12-06 16:00:17
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
    int res = 0;

    int rangeSumBST(TreeNode* root, int L, int R) {
        dfs(root, L, R);
        return res;
    }

    void dfs(TreeNode* root, int l, int r) {
        if (root == NULL) {
            return;
        }

        if (root->val < l) {
            dfs(root->right, l, r);
        } else if (root->val > r) {
            dfs(root->left, l, r);
        } else {
            res += root->val;
            dfs(root->left, l, r);
            dfs(root->right, l, r);
        }
    }
};
