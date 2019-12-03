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

        if (d == 2) {
            TreeNode *n1 = new TreeNode(v);
            TreeNode *n2 = new TreeNode(v);

            n1->left = root->left;
            n2->right = root->right;

            root->left = n1;
            root->right = n2;
            return root;
        }

        if (root->left) {
            root->left = addOneRow(root->left, v, d-1);
        }
        if (root->right) {
            root->right = addOneRow(root->right, v, d-1);
        }

        return root;
    }
};
