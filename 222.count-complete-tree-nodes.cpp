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
    int countNodes(TreeNode* root) {
        int hl = 0;
        int hr = 0;

        TreeNode *l = root;
        TreeNode *r = root;

        while (l) {
            l = l->left;
            hl += 1;
        }
        while (r) {
            r = r->right;
            hr += 1;
        }

        if (hl == hr) {
            return pow(2, hl) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
