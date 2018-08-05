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

    Trie() {
        root = new node();
    }

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
