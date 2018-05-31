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
    vector<vector<int>> res;

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL) {
            return res;
        }

        queue<TreeNode *> q;

        q.push(root);

        stack<vector<int>> stk;

        while (q.size() != 0) {
            int len = q.size();

            vector<int> v;

            for (int i = 0; i < len; i++) {
                TreeNode *top = q.front();
                q.pop();

                v.push_back(top->val);

                if (top->left != NULL) {
                    q.push(top->left);
                }
                if (top->right != NULL) {
                    q.push(top->right);
                }
            }

            stk.push(v);
        }

        while (stk.size() != 0) {
            res.push_back(stk.top());
            stk.pop();
        }
        
        return res;
    }
};
