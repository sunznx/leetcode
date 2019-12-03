// CreateTime: 2019-12-03 20:01:52
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node *root) {
        queue<Node *> q;
        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int len = q.size();
            Node *prev = NULL;
            while (len--) {
                Node *p = q.front();
                q.pop();

                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }

                if (prev) {
                    prev->next = p;
                }
                prev = p;
            }
        }
        return root;
    }
};
