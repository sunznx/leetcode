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
            TreeNode *n = (TreeNode *) malloc (sizeof(TreeNode));
            n->val = v;
            n->left = NULL;
            n->right = NULL;

            if (root) {
                n->left = root;
            }

            return n;
        }

        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }

        int depth = 1;
        while (!q.empty()) {
            depth += 1;

            int size = q.size();
            while (size--) {
                TreeNode *t = q.front();
                q.pop();

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }

                if (depth == d) {
                    TreeNode *left = (TreeNode *) malloc (sizeof(TreeNode));
                    TreeNode *right = (TreeNode *) malloc (sizeof(TreeNode));

                    left->val = v;
                    left->left = NULL;
                    left->right = NULL;

                    right->val = v;
                    right->left = NULL;
                    right->right = NULL;

                    left->left = t->left;
                    right->right = t->right;

                    t->left = left;
                    t->right = right;
                }

            }

            if (depth == d) {
                break;
            }
        }

        return root;
    }
};
