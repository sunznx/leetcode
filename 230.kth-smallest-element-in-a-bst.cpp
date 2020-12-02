// CreateTime: 2020-12-02 00:03:44
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
    int cnt = 0;
    int res = 0;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode *root, int k) {
        if (cnt > k) {
            return;
        }
        if (root->left) {
            dfs(root->left, k);
        }
        cnt += 1;
        if (cnt == k) {
            res = root->val;
            return;
        }
        if (root->right) {
            dfs(root->right, k);
        }
    }
};
