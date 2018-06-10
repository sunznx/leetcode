// CreateTime: 2018-06-10 19:01:51
class Solution {
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

    void insert(string str) {
        struct node *tmp = root;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (tmp->child[idx] == NULL) {
                tmp->child[idx] = new node;
                tmp->child[idx]->count = 0;
            }
            if (i == str.size()-1) {
                tmp->child[idx]->count += 1;
            }
            tmp = tmp->child[idx];
        }
    }

    int find(string str) {
        struct node *tmp = root;
        for (int i = 0; i < str.size(); i++) {
            int idx = str[i] - 'a';
            if (tmp->child[idx] == NULL) {
                return str.size();
            }

            if (tmp->child[idx]->count > 0) {
                return i+1;
            }
            tmp = tmp->child[idx];
        }

        return str.size();
    }


    struct node *root;

    string replaceWords(vector<string>& dict, string sentence) {
        root = new node;
        for (int i = 0; i < dict.size(); i++) {
            insert(dict[i]);
        }

        auto arr = split(' ', sentence);
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = arr[i].substr(0, find(arr[i]));
        }

        return join(arr);
    }

    vector<string> split(char delim, const string& s) {
        cout << s << endl;
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

