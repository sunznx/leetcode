// CreateTime: 2019-12-30 19:22:34
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
    int min1 = -1;
    int min2 = -1;
    bool v1 = false;
    bool v2 = false;


    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return min2;
    }

    void dfs(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        if (v1 == false || root->val < min1) {
            v1 = true;
            min2 = min1;
            min1 = root->val;
        } else if (root->val > min1 && (v2 == false || root->val < min2)) {
            v2 = true;
            min2 = root->val;
        }

        dfs(root->left);
        dfs(root->right);
    }
};
