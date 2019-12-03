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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int l, int r) {
        if (r < l) {
            return NULL;
        }

        // find max
        int maxi = l;
        for (int i = l+1; i <= r; i++) {
            if (nums[i] > nums[maxi]) {
                maxi = i;
            }
        }

        TreeNode *root = new TreeNode(nums[maxi]);
        root->left = constructMaximumBinaryTree(nums, l, maxi-1);
        root->right = constructMaximumBinaryTree(nums, maxi+1, r);
        return root;
    }
};
