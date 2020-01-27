// CreateTime: 2020-01-28 00:45:22
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) {
            return root;
        }
        
        auto &l = root->left;
        auto &r = root->right;

        l = removeLeafNodes(l, target);
        r = removeLeafNodes(r, target);
        if (l == NULL && r == NULL && root->val == target) {
            return NULL;
        }
        
        return root;
    }
};
