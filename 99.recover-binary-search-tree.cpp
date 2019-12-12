// CreateTime: 2019-12-12 08:25:26
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

    bool ok = false;
    TreeNode *prev = NULL;
    TreeNode *first;
    TreeNode *second;

    void recoverTree(TreeNode* root) {
        dfs(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void dfs(TreeNode *root) {
        if (root == NULL || ok) {
            return;
        }

        dfs(root->left);
        if (prev && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
                second = root;
            } else {
                second = root;
                ok = true;
            }
        }
        prev = root;
        dfs(root->right);
    }
};
