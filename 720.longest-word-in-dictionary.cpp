// CreateTime: 2018-06-10 15:29:49
class Solution {
public:
    struct node {
        int count;
        struct node *child[26];
    };

    struct node *root;
    string res;

    struct node *newNode() {
        struct node *n = (struct node *) malloc (sizeof(struct node));
        for (int i = 0; i < 26; i++) {
            n->child[i] = NULL;
        }

        return n;
    }

    void insert(string str) {
        struct node *tmp = root;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = newNode();
                tmp->child[idx]->count = 0;
            }
            if (i == str.size()-1) {
                tmp->child[idx]->count += 1;
            }
            tmp = tmp->child[idx];
        }

        if ((res.size() > str.size()) ||
            (res.size() == str.size() && res <= str)) {
            return;
        }

        tmp = root;
        bool ok = true;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (tmp->child[idx]->count == 0) {
                ok = false;
                break;
            }
            tmp = tmp->child[idx];
        }

        if (ok) {
            res = str;
        }
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const auto& a, const auto& b) {
                 return a.size() < b.size();
             });

        root = newNode();
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }

        return res;
    }
};
