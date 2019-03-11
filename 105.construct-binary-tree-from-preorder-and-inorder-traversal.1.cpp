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
    
    TreeNode* buildTree(vector<int>& preorder, int index, vector<int>& inorder, int l, int r) {
        if (l > r) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[index]);

        int llen;
        int rlen;
        
        for (int i = l; i <= r; i++) {
            if (inorder[i] == preorder[index]) {
                llen = i-l;
                rlen = r-i;
                break;
            }
        }
        
        root->left = buildTree(preorder, index+1, inorder, l, l+llen-1);
        root->right = buildTree(preorder, index+1+llen, inorder, r-rlen+1, r);
        return root;
    }
};
