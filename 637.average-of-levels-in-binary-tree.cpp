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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        
        queue<TreeNode*> q;
        if (root) {
            q.push(root);            
        }
        while (!q.empty()) {
            int size = q.size();
            int n = q.size();
            long long tot = 0;
            while (size--) {
                TreeNode* t = q.front();
                q.pop();
                
                tot += t->val;

                if (t->left) {
                    q.push(t->left);
                }
                if (t->right) {
                    q.push(t->right);
                }
            }
            
            res.push_back(double(tot/double(n)));
        }
        
        return res;
    }
};
