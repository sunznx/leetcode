// CreateTime: 2020-12-28 03:33:15
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int l, int r) {
        if (l > r) {
            return {NULL};
        }

        vector<TreeNode*> ans;
        for (int i = l; i <= r; i++) {
            auto lx = generateTrees(l, i-1);
            auto rx = generateTrees(i+1, r);

            for (auto &ll: lx) {
                for (auto &rr: rx) {
                    auto node = new TreeNode(i);
                    node->left = ll;
                    node->right = rr;
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
};
