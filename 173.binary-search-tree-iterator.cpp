/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int p;

    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode *root) {
        p = 0;
        inorder(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p < v.size();
    }

    /** @return the next smallest number */
    int next() {
        return v[p++];
    }
};
