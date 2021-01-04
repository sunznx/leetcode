// CreateTime: 2021-01-04 17:13:51
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
    int ans = 0;

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        helper(root, sum, m);
        return ans;
    }

    void helper(TreeNode* root, int sum, unordered_map<int, int> m, int cur = 0) {
        if (root == NULL) {
            return;
        }

        cur += root->val;
        ans += m[cur-sum];
        m[cur]++;

        helper(root->left, sum, m, cur);
        helper(root->right, sum, m, cur);
    }
};
