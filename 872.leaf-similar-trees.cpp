// CreateTime: 2019-12-14 15:57:14
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
    
    vector<int> res1;
    int res2Idx = 0;
    bool ok = true;

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        return ok;
    }

    void dfs1(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            res1.push_back(root->val);
        }
        dfs1(root->left);
        dfs1(root->right);
    }
    
    void dfs2(TreeNode *root) {
        if (!ok) {
            return;
        }
        
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            if (res1.size() == res2Idx || res1[res2Idx] != root->val) {
                ok = false;
                return;
            }
            res2Idx++;
        }
        dfs2(root->left);
        dfs2(root->right);
    }
};
