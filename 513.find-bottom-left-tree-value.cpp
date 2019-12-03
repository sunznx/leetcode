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
    int findBottomLeftValue(TreeNode* root) {
        int v;

        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }

        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *t = q.front();
                q.pop();

                if (i == 0) {
                    v = t->val;
                }

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
        }

        return v;
    }
};
