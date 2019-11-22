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

        cout << arr.size() << endl;

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
        if (str.size() == 0) {
            return 0;
        }

        auto arr = split(',', str);

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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));