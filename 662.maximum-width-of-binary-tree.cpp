// CreateTime: 2021-01-10 10:15:38
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
    int ans = 0;
    deque<TreeNode *> que;

    typedef unsigned long long ULL;

    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode *, ULL> m;
        if (root) {
            m[root] = 1;
            que.push_back(root);
        }

        while (que.size()) {
            int d = m[que.back()] - m[que.front()] + 1;
            ans = max(ans, d);

            int k = que.size();
            while (k--) {
                auto top = que.front();
                que.pop_front();

                if (top->left) {
                    m[top->left] = m[top] * 2;
                    que.push_back(top->left);
                }
                if (top->right) {
                    m[top->right] = m[top] * 2 + 1;
                    que.push_back(top->right);
                }
            }
        }

        return ans;
    }
};
