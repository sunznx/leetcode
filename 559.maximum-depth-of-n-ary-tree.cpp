// CreateTime: 2019-12-03 20:19:49
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }

        int maxlen = 0;
        for (int i = 0; i < root->children.size(); i++) {
            maxlen = max(maxlen, maxDepth(root->children[i]));
        }

        return maxlen + 1;
    }
};
