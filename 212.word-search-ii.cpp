// CreateTime: 2019-12-23 16:25:10
class Solution {
public:

    vector<int> dx = {0, -1, 0, 1};
    vector<int> dy = {-1, 0, 1, 0};

    int row;
    int col;
    vector<vector<bool>> v;
    unordered_set<string> s;

    struct node {
        int cnt;
        struct node *children[26];
        node() {
            cnt = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
    };

    struct node root;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0) {
            return res;
        }

        row = board.size();
        col = board[0].size();
        v.resize(row, vector<bool>(col));

        for (auto &word: words) {
            insert(word);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, &root, i, j);
            }
        }

        for (auto &word: s) {
            res.push_back(word);
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, struct node* root, int x, int y, string t = "") {
        if (root->cnt > 0) {
            s.insert(t);
        }

        if (x < 0 || x >= row || y < 0 || y >= col || v[x][y]) {
            return;
        }

        auto idx = board[x][y]-'a';
        if (root->children[idx] == NULL) {
            return;
        }

        v[x][y] = true;
        t.push_back(board[x][y]);
        for (int k = 0; k < 4; k++) {
            auto newX = x + dx[k];
            auto newY = y + dy[k];
            dfs(board, root->children[idx], newX, newY, t);
        }
        v[x][y] = false;
        t.pop_back();
    }

    void insert(string &word) {
        int len = word.size();

        auto n = &root;
        for (int i = 0; i < len; i++) {
            auto idx = word[i]-'a';
            if (n->children[idx] == NULL) {
                n->children[idx] = new node();
            }

            n = n->children[idx];

            if (i == len-1) {
                n->cnt += 1;
            }
        }
    }
};
