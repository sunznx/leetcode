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
        return buildTree(inorder, postorder, inorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int index, int l, int r) {
        if (l > r) {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[index]);

        int llen;
        int rlen;

        for (int i = l; i <= r; i++) {
            if (inorder[i] == postorder[index]) {
                llen = i-l;
                rlen = r-i;
            }
        }

        root->left = buildTree(inorder, postorder,  index-1-rlen, l, l+llen-1);
        root->right = buildTree(inorder, postorder, index-1, r-rlen+1, r);
        return root;
    }
};
