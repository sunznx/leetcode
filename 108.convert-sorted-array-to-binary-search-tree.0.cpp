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
    int getHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    TreeNode *insert(TreeNode *root, int x) {
        if (root == NULL) {
            return new TreeNode(x);
        }

        if (x < root->val) {
            root->left = insert(root->left, x);
        } else if (x > root->val) {
            root->right = insert(root->right, x);
        }

        int l = getHeight(root->left);
        int r = getHeight(root->right);

        if (l - r == 2) {
            root = insertFixLeft(root);
        } else if (r - l == 2) {
            root = insertFixRight(root);
        }

        return root;
    }

    TreeNode *insertFixLeft(TreeNode *root) {
        if (root->left && root->left->left) {
            root = rotateLeft(root);
        } else {
            root = rotateDoubleLeft(root);
        }

        return root;
    }

    TreeNode *insertFixRight(TreeNode *root) {
        if (root->right && root->right->right) {
            root = rotateRight(root);
        } else {
            root = rotateDoubleRight(root);
        }

        return root;
    }

    TreeNode *rotateLeft(TreeNode *root) {
        TreeNode *k1 = root->left;
        root->left = k1->right;
        k1->right = root;
        return k1;
    }

    TreeNode *rotateRight(TreeNode *root) {
        TreeNode *k1 = root->right;
        root->right = k1->left;
        k1->left = root;
        return k1;
    }

    TreeNode *rotateDoubleLeft(TreeNode *root) {
        root->left = rotateRight(root->left);
        root = rotateLeft(root);
        return root;
    }

    TreeNode *rotateDoubleRight(TreeNode *root) {
        root->right = rotateLeft(root->right);
        root = rotateRight(root);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;

        for (int i = 0; i < nums.size(); i++) {
            root = insert(root, nums[i]);
        }

        return root;
    }
};
