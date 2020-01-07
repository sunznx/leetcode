// CreateTime: 2020-01-07 11:19:55
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
    struct mycomp {
        bool operator() (const auto &a, const double &b) {
            return abs(a) < abs(b);
        }
    };

    priority_queue<double, vector<double>, mycomp> q;

    vector<int> closestKValues(TreeNode* root, double target, int k) {

        traversal(root, target, k);

        vector<int> res;
        while (q.size()) {
            res.insert(res.begin(), (int)(target+q.top()));
            q.pop();
        }
        return res;
    }

    void traversal(TreeNode *root, double target, int k) {
        if (root == NULL) {
            return;
        }

        double diff = root->val - target;

        if (q.size() < k) {
            q.push(diff);
        } else if (abs(diff) < abs(q.top())) {
            q.pop();
            q.push(diff);
        }

        traversal(root->left, target, k);
        traversal(root->right, target, k);
    }
};
