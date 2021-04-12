// CreateTime: 2021-04-13 01:17:44
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
    int pre = -1;
    bool hasPre = false;
    int ans = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        dfs(root->left);

        if (hasPre) {
            ans = min(ans, abs(root->val-pre));
        }

        hasPre = true;
        pre = root->val;

        dfs(root->right);
    }
};
