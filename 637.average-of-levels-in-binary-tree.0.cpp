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
        
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            double tot = 0;
            auto cnt = q.size();
            
            for (int i = 0; i < cnt; i++) {
                auto top = q.front();
                q.pop();
                
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
                
                tot += top->val;
            }
            
            res.push_back(tot/cnt);
        }

        return res;
    }
};
