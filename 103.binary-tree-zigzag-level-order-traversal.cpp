// CreateTime: 2020-12-22 00:39:38
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        bool lr = true;
        queue<TreeNode *> que;
        if (root != NULL) {
            que.push(root);
        }

        while (que.size()) {
            int k = que.size();
            vector<int> v;
            while (k--) {
                auto top = que.front();
                que.pop();

                v.push_back(top->val);

                if (top->left) {
                    que.push(top->left);
                }
                if (top->right) {
                    que.push(top->right);
                }
            }

            if (lr) {
                ans.push_back(v);
            } else {
                reverse(v.begin(), v.end());
                ans.push_back(v);
            }

            lr = !lr;
        }

        return ans;
    }
};