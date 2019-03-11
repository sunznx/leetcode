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
    int res = 0;

    int longestUnivaluePath(TreeNode* root) {
        postOrder(root);
        return res;
    }
    
    int postOrder(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        auto left = root->left;
        auto right = root->right;

        int l = postOrder(left);
        int r = postOrder(right);

        if (left && root->val == left->val || right && root->val == right->val) {
            int cnt = 0;
            if (left && root->val == left->val) {
                cnt += l;
            } else {
                l = 1;
            }
            if (right && root->val == right->val) {
                cnt += r;
            } else {
                r = 1;
            }
            
            res = max(res, cnt);
            return max(l, r) + 1;
        }
        
        return 1;
    }
};
