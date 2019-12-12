// CreateTime: 2019-12-13 07:34:41
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        while (root) {
            if (root->left == NULL) {
                res.push_back(root->val);
                root = root->right;
            } else {
                auto p = root->left;
                while (p->right != NULL && p->right != root) {
                    p = p->right;
                }
                
                if (p->right == NULL) {
                    p->right = root;
                    root = root->left;
                } else if (p->right == root) {
                    res.push_back(root->val);
                    p->right = NULL;
                    root = root->right;
                }
            }
        }

        return res;
    }
};
