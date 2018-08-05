class WordDictionary {
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

    WordDictionary() {
        root = new node();
    }

    void addWord(string word) {
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
        return search(word, root, 0);
    }

    bool search(string word, struct node *root, int index) {
        if (root == NULL) {
            return false;
        }

        struct node *tmp = root;
        for (int i = index; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int k = 0; k < 26; k++) {
                    if (search(word, tmp->children[k], i+1)) {
                        return true;
                    }
                }
                return false;
            } else {
                int idx = word[i] - 'a';
                if (tmp->children[idx] == NULL) {
                    return false;
                }
                tmp = tmp->children[idx];
            }
        }

        return tmp != NULL && tmp->count > 0;
    }
};
