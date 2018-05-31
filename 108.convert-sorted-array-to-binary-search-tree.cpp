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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }

        return sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        }

        int mid = (l+r) / 2;
        TreeNode *root = (TreeNode *) malloc (sizeof(TreeNode));

        if (l == r) {
            root->val = nums[mid];
            root->left = NULL;
            root->right = NULL;
        } else {
            root->val = nums[mid];
            root->left = sortedArrayToBST(nums, l, mid-1);
            root->right = sortedArrayToBST(nums, mid+1, r);
        }

        return root;
    }
};
