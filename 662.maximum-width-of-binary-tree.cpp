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
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode *> q;
        if (root) {
            q.push_back(root);
        }

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            ans = max(ans, size);

            for (int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop_front();

                if (t == NULL) {
                    q.push_back(NULL);
                    q.push_back(NULL);
                } else {
                    q.push_back(t->left);
                    q.push_back(t->right);
                }
            }

            while (!q.empty()) {
                if (q.front() == NULL) {
                    q.pop_front();
                } else {
                    break;
                }
            }
            while (!q.empty()) {
                if (q.back() == NULL) {
                    q.pop_back();
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
