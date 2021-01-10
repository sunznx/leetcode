// CreateTime: 2021-01-10 10:39:41
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    deque<TreeNode *> que;

    int widthOfBinaryTree(TreeNode* root) {
        if (root) {
            root->val = 1;
            que.push_back(root);
        }

        while (que.size()) {
            int d = que.back()->val - que.front()->val + 1;
            ans = max(ans, d);

            int x = que.back()->val;

            int k = que.size();
            while (k--) {
                auto top = que.front();
                que.pop_front();

                if (top->left) {
                    top->left->val = (top->val-x) * 2;
                    que.push_back(top->left);
                }
                if (top->right) {
                    top->right->val = (top->val-x) * 2 + 1;
                    que.push_back(top->right);
                }
            }
        }

        return ans;
    }
};
