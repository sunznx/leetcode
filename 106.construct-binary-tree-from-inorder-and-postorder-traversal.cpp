// CreateTime: 2019-12-03 19:35:10
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
        if (postorder.empty() || inorder.empty()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder.back());
        vector<int> l;
        vector<int> r;
        postorder.pop_back();

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

        root->right = buildTree(r, postorder);
        root->left = buildTree(l, postorder);

        return root;
    }
};
