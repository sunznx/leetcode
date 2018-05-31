class Solution {
public:
    vector<string> v;

    void dfs(TreeNode *root, string s = "") {
        if (root->left == NULL && root->right == NULL) {
            v.push_back(s);
            return;
        }

        if (root->left) {
            dfs(root->left, s + "->"  + to_string(root->left->val));
        }

        if (root->right) {
            dfs(root->right, s + "->" + to_string(root->right->val));
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return v;
        }

        dfs(root, to_string(root->val));

        return v;
    }
};
