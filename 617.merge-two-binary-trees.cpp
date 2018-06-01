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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        
        TreeNode *root = (TreeNode *) malloc (sizeof(TreeNode));
        
        if (t1 == NULL) {
            root->val = t2->val;
            root->left = mergeTrees(t1, t2->left);
            root->right = mergeTrees(t1, t2->right);
        } else if (t2 == NULL) {
            root->val = t1->val;
            root->left = mergeTrees(t1->left, t2);
            root->right = mergeTrees(t1->right, t2);
        } else {
            root->val = t1->val + t2->val;
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        }
        
        return root;
    }
};
