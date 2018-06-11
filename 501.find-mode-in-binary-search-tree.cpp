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
    vector<int> res;
    int maxn = 0;
    int maxv = INT_MAX;
    TreeNode *prev = NULL;
    map<int, int> m;

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) {
            return res;
        }

        travesal(root);
        return res;
    }

    void travesal(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        if (root->left) {
            travesal(root->left);
        }

        if (root->right) {
            travesal(root->right);
        }

        m[root->val] += 1;
        if (m[root->val] > maxn) {
            maxn = m[root->val];
            res.clear();
            res.push_back(root->val);
        } else if (m[root->val] == maxn) {
            res.push_back(root->val);
        }
    }
};
