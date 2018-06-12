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
    unordered_map<int, int> m;
    int maxn = INT_MIN;
    vector<int> res;

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);

        int cur = l + r + root->val;

        m[cur] += 1;
        if (m[cur] > maxn) {
            maxn = m[cur];
            res.clear();
            res.push_back(cur);
        } else if (m[cur] == maxn) {
            res.push_back(cur);
        }

        return cur;
    }
};
