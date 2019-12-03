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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int idx, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return NULL;
        }

        int i;
        int llen = 0;
        int rlen = r-l;
        for (i = l; i <= r; i++) {
            if (preorder[idx] == inorder[i]) {
                break;
            }

            llen++;
            rlen--;
        }

        TreeNode *root = new TreeNode(preorder[idx]);
        root->left = buildTree(preorder, idx+1, inorder, l, i-1);
        root->right = buildTree(preorder, idx+1+llen, inorder, i+1, r);
        return root;
    }
};
