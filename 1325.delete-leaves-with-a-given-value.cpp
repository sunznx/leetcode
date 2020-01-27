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
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (root->left == NULL && root->right == NULL) {
            if (root->val == target) {
                return NULL;
            } else {
                return root;
            }
        }
        
        return root;
    }
};
