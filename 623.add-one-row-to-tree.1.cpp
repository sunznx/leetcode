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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *n = new TreeNode(v);
            n->left = root;
            return n;
        }

        queue<TreeNode *> q;

        if (root) {
            q.push(root);
        }

        int tmp = 2;
        while (q.size() && tmp <= d) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *t = q.front();
                q.pop();

                if (tmp == d) {
                    TreeNode *n1 = new TreeNode(v);
                    TreeNode *n2 = new TreeNode(v);
                    n1->left = t->left;
                    t->left = n1;

                    n2->right = t->right;
                    t->right = n2;
                }

                if (tmp != d) {
                    if (t->left) {
                        q.push(t->left);
                    }
                    if (t->right) {
                        q.push(t->right);
                    }
                }
            }

            tmp += 1;
        }

        return root;
    }
};
