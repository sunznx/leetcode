// CreateTime: 2020-12-28 23:50:21
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
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if (l > r) {
            return NULL;
        }
        
        int m = (l+r) / 2;
        auto x = nums[m];
        
        auto left = sortedArrayToBST(nums, l, m-1);
        auto right = sortedArrayToBST(nums, m+1, r);
        return new TreeNode(x, left, right);
    }
};
