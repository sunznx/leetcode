// CreateTime: 2019-12-13 01:08:41
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        stack<pair<TreeNode *, int>> stk;

        if (root) {
            stk.push({root, false});
        }

        while (stk.size()) {
            auto top = stk.top();
            stk.pop();

            auto node = top.first;
            auto marked = top.second;

            if (marked) {
                res.push_back(node->val);
            } else {
                stk.push({node, true});

                if (node->right) {
                    stk.push({node->right, false});
                }
                if (node->left) {
                    stk.push({node->left, false});
                }
            }
        }

        return res;
    }
};
