/*
// Definition for a Node.
class Node {
public:
int val = NULL;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;

        queue<Node *> q;
        if (root) {
            q.push(root);
        }

        while (q.size()) {
            int len = q.size();

            vector<int> v;
            for (int i = 0; i < len; i++) {
                Node *t = q.front();
                q.pop();

                v.push_back(t->val);
                for (int j = 0; j < t->children.size(); j++) {
                    Node *n = t->children[j];
                    q.push(n);
                }
            }

            res.push_back(v);
        }

        return res;
    }
};
