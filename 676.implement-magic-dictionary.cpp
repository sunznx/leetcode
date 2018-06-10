// CreateTime: 2018-06-10 16:57:39
class MagicDictionary {
public:
    struct node {
        int count;
        struct node *child[26];

        node() {
            count = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    struct node *root;


    void insert(string key) {
        struct node *tmp = root;
        for (int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = new node();
            }
            if (i == key.size()-1) {
                tmp->child[idx]->count += 1;
            }

            tmp = tmp->child[idx];
        }
    }


    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new node();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i = 0; i < dict.size(); i++) {
            string pre = dict[i];
            for (int j = 0; j < pre.size(); j++) {
                for (int x = 0; x < 26; x++) {
                    dict[i][j] = 'a' + x;
                    if (dict[i] == pre) {
                        continue;
                    }
                    insert(dict[i]);
                }
                dict[i] = pre;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        struct node *tmp = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (tmp->child[idx] == NULL) {
                return false;
            }

            if (i == word.size()-1) {
                if (tmp->child[idx]->count > 0) {
                    return true;
                } else {
                    return false;
                }
            }
            tmp = tmp->child[idx];
        }

        return false;
    }
};
