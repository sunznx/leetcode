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
    int res = 0;

    int sumOfLeftLeaves(TreeNode* root) {
        traversal(root, false);
        return res;
    }
    
    void traversal(TreeNode *root, bool isLeft) {
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            if (isLeft) {
                res += root->val;
            }
            return;
        }
        
        if (root->left) {
            traversal(root->left, true);
        }
        if (root->right) {
            traversal(root->right, false);
        }
    }
};
