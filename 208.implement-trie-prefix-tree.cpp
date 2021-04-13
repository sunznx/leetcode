// CreateTime: 2021-04-14 00:01:56
class Trie {
public:
    class node {
    public:
        struct node *child[26];
        bool isEnd = false;
    };

    node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto n = root;
        for (auto &x: word) {
            auto k = x-'a';
            if (n->child[k] == NULL) {
                n->child[k] = new node();
            }
            n = n->child[k];
        }
        n->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto n = root;
        for (auto &x: word) {
            auto k = x-'a';
            if (n->child[k] == NULL) {
                return false;
            }
            n = n->child[k];
        }
        return n->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto n = root;
        for (auto &x: prefix) {
            auto k = x-'a';
            if (n->child[k] == NULL) {
                return false;
            }
            n = n->child[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
