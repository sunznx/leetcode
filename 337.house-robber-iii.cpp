// CreateTime: 2019-12-12 14:12:28
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

    unordered_map<TreeNode *, int> m;

    int rob(TreeNode* root) {
        if (m.find(root) != m.end()) {
            return m[root];
        }

        if (root == NULL) {
            return 0;
        }

        auto l = rob(root->left);
        auto r = rob(root->right);

        auto l1 = 0;
        auto r1 = 0;
        auto l2 = 0;
        auto r2 = 0;

        if (root->left) {
            l1 = rob(root->left->left);
            r1 = rob(root->left->right);
        }

        if (root->right) {
            l2 = rob(root->right->left);
            r2 = rob(root->right->right);
        }

        return m[root] = max(root->val+l1+r1+l2+r2, l+r);
    }
};
