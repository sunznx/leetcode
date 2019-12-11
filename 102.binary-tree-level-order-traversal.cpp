// CreateTime: 2019-12-11 14:34:30
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode *> q;

        if (root) {
            q.push(root);
        }
        while (q.size()) {
            int len = q.size();
            vector<int> v;
            for (int i = 0; i < len; i++) {
                auto top = q.front();
                q.pop();
                v.push_back(top->val);

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }
            }
            res.push_back(v);
        }

        return res;
    }
};
