// CreateTime: 2019-12-02 12:46:03
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

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        traversal(root, m, sum, 0);
        return res;
    }

    void traversal(TreeNode* root, unordered_map<int, int> m, int sum, int tot) {
        if (root == NULL) {
            return;
        }

        tot += root->val;
        res += m[tot-sum];
        m[tot] += 1;

        traversal(root->left, m, sum, tot);
        traversal(root->right, m, sum, tot);
    }
};
