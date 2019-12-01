// CreateTime: 2019-12-01 13:56:57
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
    unordered_map<string, int> m;
    vector<TreeNode*> res;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traversal(root);
        return res;
    }
    
    string traversal(TreeNode *root) {
        if (root == NULL) {
            return "null";
        }
        
        auto l = traversal(root->left);
        auto r = traversal(root->right);
        string s = "[" + to_string(root->val) + "," + l + "," + r + "]";
        if (m[s] == 1) {
            res.push_back(root);
        }
        m[s] += 1;
        return s;
    }
};
