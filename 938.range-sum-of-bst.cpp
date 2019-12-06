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
    int res;

    int rangeSumBST(TreeNode* root, int L, int R) {
        res = 0;
        dfs(root, L, R);
        return res;
    }

    void dfs(TreeNode* root, int l, int r) {
        if (root == NULL) {
            return;
        }

        if (l <= root->val && root->val <= r) {
            res += root->val;
        }
        dfs(root->left, l, r);
        dfs(root->right, l, r);
    }
};
