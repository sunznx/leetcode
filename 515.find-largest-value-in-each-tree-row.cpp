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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }

        while (q.size()) {
            int len = q.size();

            int maxv;
            for (int i = 0; i < len; i++) {
                TreeNode *t = q.front();
                q.pop();

                if (i == 0 || t->val > maxv) {
                    maxv = t->val;
                }

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }

            res.push_back(maxv);
        }

        return res;
    }
};
