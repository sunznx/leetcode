class Solution {
public:

    struct trie {
        int count;
        struct trie *child[26];
    };

    struct trie *root;
    string res;

    struct trie *newNode() {
        struct trie *n = (struct trie *) malloc (sizeof(struct trie));
        for (int i = 0; i < 26; i++) {
            n->child[i] = NULL;
        }
        n->count = 0;
        return n;
    }

    void insert(string str) {
        int len = str.size();
        if (len == 0) {
            return;
        }

        struct trie *tmp = root;
        for (int i = 0; i < len; i++) {
            int idx = str[i] - 'a';
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = newNode();
            }
            tmp = tmp->child[idx];
        }
        tmp->count += 1;

        tmp = root;
        bool ok = true;
        for (int i = 0; i < len; i++) {
            int idx = str[i] - 'a';
            tmp = tmp->child[idx];
            if (tmp->count == 0) {
                ok = false;
                break;
            }
        }

        if (ok && (str.size() > res.size() || str.size() == res.size() && str < res)) {
            res = str;
        }
    }

    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const auto& a, const auto& b) {
                 return a.size() < b.size();
             });

        res = "";
        root = newNode();

        int len = words.size();
        for (int i = 0; i < len; i++) {
            insert(words[i]);
        }

        return res;
    }
};
