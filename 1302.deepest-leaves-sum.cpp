// CreateTime: 2019-12-30 19:43:44
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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;

        queue<TreeNode *> q;

        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int len = q.size();

            int v = 0;
            for (int i = 0; i < len; i++) {
                auto top = q.front();
                q.pop();

                v += top->val;
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
            res = v;
        }

        return res;
    }
};
