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
        return buildTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int index, int l, int r) {
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
        
        root->left = buildTree(preorder, inorder, index+1, l, l+llen-1);
        root->right = buildTree(preorder, inorder, index+1+llen, r-rlen+1, r);
        return root;
    }
};
