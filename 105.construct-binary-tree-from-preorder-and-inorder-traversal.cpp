// CreateTime: 2019-12-03 19:33:28
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
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder.front());
        vector<int> l;
        vector<int> r;
        preorder.erase(preorder.begin());

        int x = 0;
        while (inorder[x] != root->val) {
            l.push_back(inorder[x]);
            x++;
        }

        x += 1;

        while (x < inorder.size()) {
            r.push_back(inorder[x]);
            x++;
        }

        root->left = buildTree(preorder, l);
        root->right = buildTree(preorder, r);

        return root;
    }
};
