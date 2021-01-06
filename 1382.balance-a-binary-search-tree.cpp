// CreateTime: 2021-01-06 08:43:20
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
    vector<int> arr;

    void getInorder(TreeNode* root) {
        if (root->left) {
            getInorder(root->left);
        }

        arr.push_back(root->val);

        if (root->right) {
            getInorder(root->right);
        }
    }

    TreeNode* build(int l, int r) {
        if (l > r) {
            return NULL;
        }

        int m = (l+r) / 2;
        TreeNode* root = new TreeNode(arr[m]);

        root->left = build(l, m-1);
        root->right = build(m+1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, arr.size()-1);
    }
};