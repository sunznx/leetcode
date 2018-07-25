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
    int res;

    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        res = 0;
        sumNumbersHelp(root, 0);
        return res;
    }

    void sumNumbersHelp(TreeNode *root, int cur) {
        cur = cur * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            res += cur;
            return;
        }
        if (root->left) {
            sumNumbersHelp(root->left, cur);
        }
        if (root->right) {
            sumNumbersHelp(root->right, cur);
        }
    }
};
