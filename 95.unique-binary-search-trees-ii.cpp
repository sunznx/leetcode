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

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {NULL};
        }

        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            auto l = generateTrees(start, i-1);
            auto r = generateTrees(i+1, end);

            for (auto &lx: l) {
                for (auto &rx: r) {
                    auto node = new TreeNode(i, lx, rx);
                    ans.push_back(node);
                }
            }
        }

        return ans;
    }
};
