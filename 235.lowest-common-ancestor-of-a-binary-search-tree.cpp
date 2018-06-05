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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        int v1 = p->val;
        int v2 = q->val;

        if (v1 > v2) {
            return lowestCommonAncestor(root, q, p);
        }

        if (root->val > v1 && root->val > v2) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < v1 && root->val < v2) {
            return lowestCommonAncestor(root->right, p, q);
        }

        if (v1 <= root->val && root->val <= v2) {
            return root;
        }
    }
};
