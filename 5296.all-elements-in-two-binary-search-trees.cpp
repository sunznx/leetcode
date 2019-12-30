// CreateTime: 2019-12-30 09:55:27
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1;
        vector<int> arr2;
        
        dfs(arr1, root1);
        dfs(arr2, root2);
        
        int len1 = arr1.size();
        int len2 = arr2.size();
        
        vector<int> res(len1+len2);

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < len1 || j < len2) {
            if (i == len1) {
                res[k++] = arr2[j++];
            } else if (j == len2) {
                res[k++] = arr1[i++];
            } else if (arr1[i] < arr2[j]) {
                res[k++] = arr1[i++];
            } else {
                res[k++] = arr2[j++];
            }
        }
        
        return res;
    }
    
    void dfs(vector<int> &arr, TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        dfs(arr, root->left);
        arr.push_back(root->val);
        dfs(arr, root->right);
    }
};
