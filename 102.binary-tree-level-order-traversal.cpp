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

        queue<TreeNode *> que;

        if (root) {
            que.push(root);
        }

        while (que.size()) {
            vector<int> sub;

            auto k = que.size();
            while (k--) {
                auto top = que.front();
                que.pop();

                sub.push_back(top->val);

                if (top->left) {
                    que.push(top->left);
                }

                if (top->right) {
                    que.push(top->right);
                }
            }

            res.push_back(sub);
        }

        return res;
    }
};
