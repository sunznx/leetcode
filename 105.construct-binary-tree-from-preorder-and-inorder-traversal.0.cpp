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
        return buildTreeHelp(preorder, 0, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* buildTreeHelp(vector<int>& preorder, int idx, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return NULL;
        }
        
        int llen = 0;
        int rlen = r-l;
        
        for (int i = l; i <= r; i++) {
            if (inorder[i] == preorder[idx]) {
                break;
            }
            llen++;
            rlen--;
        }
        
        TreeNode *root = new TreeNode(preorder[idx]);
        root->left = buildTreeHelp(preorder, idx+1, inorder, l, l+llen-1);
        root->right = buildTreeHelp(preorder, idx+1+llen, inorder, r-rlen+1, r);
        return root;
    }
};
