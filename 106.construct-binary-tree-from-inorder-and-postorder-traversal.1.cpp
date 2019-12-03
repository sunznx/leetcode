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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size()-1, postorder, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& inorder, int l, int r, vector<int>& postorder, int idx) {
        if (l > r) {
            return NULL;
        }

        int i;
        int llen = 0;
        int rlen = r-l;
        for (i = l; i <= r; i++) {
            if (postorder[idx] == inorder[i]) {
                break;
            }

            llen++;
            rlen--;
        }

        TreeNode *root = new TreeNode(postorder[idx]);
        root->right = buildTree(inorder, i+1, r, postorder, idx-1);
        root->left = buildTree(inorder, l, i-1, postorder, idx-1-rlen);
        return root;
    }
};
