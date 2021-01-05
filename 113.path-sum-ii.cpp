// CreateTime: 2021-01-05 11:14:49
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
    vector<vector<int>> ans;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root, sum);
        return ans;
    }

    void helper(TreeNode *root, int sum, vector<int> path = vector<int>()) {
        if (root == NULL) {
            return;
        }

        path.push_back(root->val);
        sum -= root->val;

        if (root->left == NULL && root->right == NULL && sum == 0) {
            ans.push_back(path);
        }

        helper(root->left, sum, path);
        helper(root->right, sum, path);
    }
};
