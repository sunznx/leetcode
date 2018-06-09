class Trie {
public:
    struct node {
        struct node *child[26];
        char data;
        bool isWord;

        node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            isWord = false;
        }

        void insert(char c, bool isLast = false) {
            int index = c - 'a';
            if (child[index] == NULL) {
                child[index] = (struct node *) malloc (sizeof(struct node));
                for (int i = 0; i < 26; i++) {
                    child[index]->child[i] = NULL;
                }
                child[index]->isWord = isLast;
            }
            child[index]->data = c;
            
            if (isLast == true) {
                child[index]->isWord = isLast;
            }
        }
    };
    
    struct node *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.size();

        struct node *tmp = root;
        for (int i = 0; i < len; i++) {
            if (i == len-1) {
                tmp->insert(word[i], true);
            } else {
                tmp->insert(word[i], false);
            }
            tmp = tmp->child[word[i]-'a'];
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.size();
        struct node *tmp = root;
        for (int i = 0; i < len; i++) {
            if (tmp->child[word[i]-'a'] == NULL) {
                return false;
            }
            tmp = tmp->child[word[i]-'a'];
        }

        return tmp->isWord == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.size();
        struct node *tmp = root;
        for (int i = 0; i < len; i++) {
            if (tmp->child[prefix[i]-'a'] == NULL) {
                return false;
            }
            tmp = tmp->child[prefix[i]-'a'];
        }

        return true;
    }
};
