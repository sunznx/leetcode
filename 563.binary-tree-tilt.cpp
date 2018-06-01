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
    int findTilt(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return findTilt(root, 0);
    }

    int findTilt(TreeNode *root, int res) {
        int left = findTilt(root->left);
        int right = findTilt(root->right);
        return left + right + abs(sum(root->left) - sum(root->right));
    }

    int sum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return sum(root->left) + sum(root->right) + root->val;
    }
};




// class Solution {
// public:
//     int res = 0;

//     int postOrder(TreeNode *root) {
//         if (root == NULL) {
//             return 0;
//         }

//         int left = postOrder(root->left);
//         int right = postOrder(root->right);

//         res += abs(left - right);

//         return left + right + root->val;;
//     }

//     int findTilt(TreeNode *root) {
//         postOrder(root);
//         return res;
//     }
// };
