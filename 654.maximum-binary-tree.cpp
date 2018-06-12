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
        return cons(nums, 0, nums.size()-1);
    }

    TreeNode* cons(vector<int>& nums, int i, int j) {
        int l = 0;
        int r = nums.size()-1;

        if (i > j || i > r || i < l || j < l || j > r) {
            return NULL;
        }

        int maxn = i;
        for (int x = i; x <= j; x++) {
            if (nums[x] >= nums[maxn]) {
                maxn = x;
            }
        }

        TreeNode *node = (TreeNode *) malloc (sizeof(TreeNode));
        node->val = nums[maxn];
        node->left = cons(nums, i, maxn-1);
        node->right = cons(nums, maxn+1, j);
        return node;
    }
};
