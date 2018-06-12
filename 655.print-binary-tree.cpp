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
    vector<vector<string>> printTree(TreeNode* root) {
        int raw = getRaw(root);
        int col = getCol(raw);

        vector<vector<string>> m(raw, vector<string>(col, ""));
        dfs(root, m, 0, 0, col);
        return m;
    }

    void dfs(TreeNode *root, vector<vector<string>> &m, int row, int start, int end) {
        if (root == NULL) {
            return;
        }

        int mid = (start + end) / 2;
        m[row][mid] = to_string(root->val);

        dfs(root->left, m, row+1, start, mid-1);
        dfs(root->right, m, row+1, mid+1, end);
    }

    int getRaw(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        return max(getRaw(root->left), getRaw(root->right)) + 1;
    }

    int getCol(int h) {
        int res = 0;

        for (int i = 1; i <= h; i++) {
            res += (int)pow(2, i-1);
        }

        return res;
    }
};
