// CreateTime: 2019-12-03 19:36:46
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
    Node *connect(Node *root) {
        connect(NULL, root);
        return root;
    }
    
    void connect(Node *prev, Node *root) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL) {
            return;
        }

        root->left->next = root->right;
        
        if (prev == NULL) {
            connect(NULL, root->left);
            connect(root->left, root->right);
        } else {
            prev->right->next = root->left;
            connect(prev->right, root->left);
            connect(root->left, root->right);
        }
    }
};
