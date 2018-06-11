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
    bool findTarget(TreeNode* root, int k) {
        return findTarget(root, root, k);
    }

    bool findTarget(TreeNode* root, TreeNode *cur, int k) {
        if (cur == NULL) {
            return false;
        }

        int v = k - cur->val;

        if (findValue(root, cur, v)) {
            return true;
        }

        return findTarget(root, cur->left, k)
            || findTarget(root, cur->right, k);
    }

    bool findValue(TreeNode *root, TreeNode *cur, int v) {
        if (root == NULL) {
            return false;
        }

        if (root->val == v && root != cur) {
            return true;
        }

        if (root->val > v) {
            return findValue(root->left, cur, v);
        } else {
            return findValue(root->right, cur, v);
        }
    }
};
