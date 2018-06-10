// CreateTime: 2018-06-10 16:12:49
class MapSum {
public:
    struct node {
        int count;
        int val;
        struct node *child[26];

        node() {
            count = 0;
            val = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
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
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = new node();
            }
            if (i == key.size()-1) {
                tmp->child[idx]->val = val;
                tmp->child[idx]->count += 1;
            }

            tmp = tmp->child[idx];
        }
    }

    int sum(string prefix) {
        struct node *tmp = root;
        int res = 0;
        for (int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (tmp->child[idx] == NULL) {
                return 0;
            }
            tmp = tmp->child[idx];
        }

        return sumFromNode(tmp);
    }

    int sumFromNode(struct node *root) {
        int res = 0;
        if (root->count > 0) {
            res += root->val;
        }

        for (int i = 0; i < 26; i++) {
            if (root->child[i]) {
                res += sumFromNode(root->child[i]);
            }
        }

        return res;
    }
};



