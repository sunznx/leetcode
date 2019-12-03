/*
// Definition for a Node.
class Node {
public:
int val;
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
    vector<int> res;

    vector<int> preorder(Node* root) {
        preorderHelp(root);
        return res;
    }

    void preorderHelp(Node *root) {
        if (root == NULL) {
            return;
        }

        res.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            Node *n = root->children[i];
            preorderHelp(n);
        }
    }
};
