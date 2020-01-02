// CreateTime: 2019-12-23 16:05:22
class Trie {
public:

    struct node {
        int count;
        struct node *children[26];

        node () {
            count = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    struct node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        struct node *tmp = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (tmp->children[idx] == NULL) {
                tmp->children[idx] = new node();
            }

            if (i == word.size()-1) {
                tmp->children[idx]->count = 1;
            }
            tmp = tmp->children[idx];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        struct node *tmp = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (tmp->children[idx] == NULL) {
                return false;
            }
            tmp = tmp->children[idx];
        }

        return tmp != NULL && tmp->count > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        struct node *tmp = root;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (tmp->children[idx] == NULL) {
                return false;
            }
            tmp = tmp->children[idx];
        }

        return true;
    }
};
