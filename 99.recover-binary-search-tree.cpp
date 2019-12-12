// CreateTime: 2019-11-22 07:48:29
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode *> q;

        q.push(root);
        vector<string> arr;
        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();

                if (t == NULL) {
                    arr.push_back("null");
                } else {
                    arr.push_back(to_string(t->val));
                    q.push(t->left);
                    q.push(t->right);
                }
            }
        }

        while (arr.size() > 0 && arr[arr.size()-1] == "null") {
            arr.pop_back();
        }

        string res = "";
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size()-1) {
                res += arr[i];
            } else {
                res += arr[i] + ",";
            }
        }

        return "[" + res + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string str = data.substr(1, data.size()-2);
        auto arr = split(',', str);

        if (arr.size() == 0) {
            return NULL;
        }

        TreeNode *root;

        queue<TreeNode **> q;
        q.push(&root);

        for (int i = 0; i < arr.size(); i++) {
            auto t = q.front();
            q.pop();

            if (arr[i] == "null") {
                (*t) = NULL;
            } else {
                (*t) = new TreeNode(atoi(arr[i].c_str()));
                q.push(&(*t)->left);
                q.push(&(*t)->right);
            }
        }

        return root;
    }

    vector<string> split(char delim, const string& s) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
};


// CreateTime: 2019-12-12 08:25:26
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

    bool ok = false;
    TreeNode *prev = NULL;
    TreeNode *first;
    TreeNode *second;

    void recoverTree(TreeNode* root) {
        dfs(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void dfs(TreeNode *root) {
        if (root == NULL || ok) {
            return;
        }

        dfs(root->left);
        if (prev && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
                second = root;
            } else {
                second = root;
                ok = true;
            }
        }
        prev = root;
        dfs(root->right);
    }
};
