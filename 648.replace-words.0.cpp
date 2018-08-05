class Solution {
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

    string replaceWord(string &s) {
        string res;
        struct node *tmp = root;
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (tmp->children[idx] == NULL) {
                return s;
            }
            tmp = tmp->children[idx];
            res += s[i];
            if (tmp->count > 0) {
                return res;
            }
        }
        return res;
    }

    struct node *root;

    string replaceWords(vector<string>& dict, string sentence) {
        root = new node();

        auto l = split(' ', sentence);
        for (int i = 0; i < dict.size(); i++) {
            insert(dict[i]);
        }

        for (int i = 0; i < l.size(); i++) {
            l[i] = replaceWord(l[i]);
        }

        return join(l);
    }

    vector<string> split(char delim, const string& s) {
        stringstream ss(s);
        string item;
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    string join(vector<string>& v) {
        string res = "";
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                res = v[0];
            } else {
                res += " " + v[i];
            }
        }

        return res;
    }
};
