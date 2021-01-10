// CreateTime: 2021-01-10 10:11:32
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
    vector<int> ans;
    queue<TreeNode *> que;

    vector<int> rightSideView(TreeNode* root) {
        if (root) {
            que.push(root);
        }

        while (que.size()) {
            auto k = que.size();

            int val = que.front()->val;
            while (k--) {
                auto top = que.front();
                que.pop();

                if (top->left) {
                    que.push(top->left);
                }

                if (top->right) {
                    que.push(top->right);
                }

                val = top->val;
            }

            ans.push_back(val);
        }

        return ans;
    }
};
