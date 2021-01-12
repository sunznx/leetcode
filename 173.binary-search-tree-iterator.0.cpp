// CreateTime: 2021-01-12 13:08:45
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
class BSTIterator {
public:
    stack<TreeNode *> stk;

    BSTIterator(TreeNode* root) {
        leftMost(root);
    }
    
    int next() {
        auto top = stk.top();
        stk.pop();
        if (top->right) {
            leftMost(top->right);
        }
        return top->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
    void leftMost(TreeNode *root) {
        auto p = root;
        while (p) {
            stk.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
