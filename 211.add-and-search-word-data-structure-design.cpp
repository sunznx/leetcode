// CreateTime: 2018-06-10 19:42:33
class WordDictionary {
public:
    struct node {
        int count;
        struct node *child[26];

        node () {
            count = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    struct node *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        struct node *tmp = root;

        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = new node;
            }
            if (i == word.size()-1) {
                tmp->child[idx]->count += 1;
            }
            tmp = tmp->child[idx];
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(0, word, root);
    }

    bool dfs(int n, string word, struct node *p) {
        if (n == word.size()) {
            if (p->count > 0) {
                return true;
            } else {
                return false;
            }
        }

        // check n
        if (word[n] == '.') {
            for (int i = 0; i < 26; i++) {
                if (p->child[i]) {
                    bool ok = dfs(n+1, word, p->child[i]);
                    if (ok) {
                        return true;
                    }
                }
            }
            return false;
        } else {
            int idx = word[n] - 'a';
            if (p->child[idx]) {
                return dfs(n+1, word, p->child[idx]);
            } else {
                return false;
            }
        }
    }
};
