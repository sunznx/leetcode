class MapSum {
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

    MapSum() {
        root = new node();
    }

    void insert(string key, int val) {
        struct node *tmp = root;
        for (int i = 0; i < key.size(); i++) {
            int idx = key[i] - 'a';
            if (tmp->children[idx] == NULL) {
                tmp->children[idx] = new node();
            }

            if (i == key.size()-1) {
                tmp->children[idx]->count = val;
            }
            tmp = tmp->children[idx];
        }
    }

    int sum(string prefix) {
        struct node *tmp = root;

        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (tmp->children[idx] == NULL) {
                return 0;
            }
            tmp = tmp->children[idx];
        }

        return sumHelp(tmp);
    }

    int sumHelp(struct node *root) {
        if (root == NULL) {
            return 0;
        }

        int res = root->count;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] == NULL) {
                continue;
            }
            res += sumHelp(root->children[i]);
        }

        return res;
    }
};
