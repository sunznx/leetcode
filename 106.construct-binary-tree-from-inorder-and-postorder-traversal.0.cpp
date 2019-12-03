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
        return buildTreeHelp(inorder, 0, inorder.size()-1, postorder, inorder.size()-1);
    }

    TreeNode* buildTreeHelp(vector<int>& inorder, int l, int r, vector<int>& postorder, int idx) {
        if (l > r) {
            return NULL;
        }

        int llen = 0;
        int rlen = r-l;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == postorder[idx]) {
                break;
            }
            llen++;
            rlen--;
        }

        TreeNode *root = new TreeNode(postorder[idx]);
        root->left = buildTreeHelp(inorder, l, l+llen-1, postorder, idx-1-rlen);
        root->right = buildTreeHelp(inorder, r-rlen+1, r, postorder, idx-1);
        return root;
    }
};
