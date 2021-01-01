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

        queue<Node *> que;
        if (root) {
            que.push(root);
        }

        while (que.size()) {
            auto k = que.size();

            vector<int> sub;
            while (k--) {
                auto top = que.front();
                que.pop();

                sub.push_back(top->val);
                for (auto child: top->children) {
                    if (child) {
                        que.push(child);
                    }
                }
            }

            res.push_back(sub);
        }

        return res;
    }
};
