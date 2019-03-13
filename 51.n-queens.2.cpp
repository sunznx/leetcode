class Solution {
public:
    vector<int> c1;
    vector<int> c2;
    vector<int> c3;
    vector<int> c4;
    vector<string> q;
    int n;
    int marked;
    vector<vector<string>> res;

    void init(int num) {
        n = num;
        marked = 0;

        for (int i = 0; i <= 2*n; i++) {
            c1.push_back(0);
            c2.push_back(0);
            c3.push_back(0);
            c4.push_back(0);
        }

        for (int i = 0; i < n; i++) {
            q.push_back(string(n, '.'));
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        init(n);
        dfs(0);
        return res;
    }

    void dfs(int x) {
        if (x == n) {
            res.push_back(q);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (check(x, j)) {
                mark(x, j);
                dfs(x+1);
                unmark(x, j);
            }
        }
    }

    void mark(int x, int y) {
        c1[x] = 1;
        c2[y] = 1;
        c3[y-x+n] = 1;
        c4[x+y] = 1;
        q[x][y] = 'Q';
        marked += 1;
    }

    void unmark(int x, int y) {
        c1[x] = 0;
        c2[y] = 0;
        c3[y-x+n] = 0;
        c4[x+y] = 0;
        q[x][y] = '.';
        marked -= 1;
    }

    bool check(int x, int y) {
        return c1[x] == 0 && c2[y] == 0 && c3[y-x+n] == 0 && c4[x+y] == 0;
    }
};
