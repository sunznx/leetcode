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
    TreeNode *top;

    bool findTarget(TreeNode* root, int k) {
        top = root;
        return findTargetHelp(root, k);
    }

    bool findTargetHelp(TreeNode *root, int k) {
        if (root == NULL) {
            return false;
        }
        return binSearch(root, k-root->val) || findTargetHelp(root->right, k) || findTargetHelp(root->left, k);
    }

    bool binSearch(TreeNode *n, int k) {
        TreeNode *root = top;
        while (root != NULL) {
            if (k == root->val) {
                if (n == root) {
                    return false;
                }
                return true;
            } else if (k > root->val) {
                root = root->right;
            } else if (k < root->val) {
                root = root->left;
            }

        }

        return false;
    }
};
