class Solution {
public:
    vector<int> c1;
    vector<int> c2;
    vector<int> c3;
    vector<int> c4;
    vector<string> q;
    int num;
    int marked;
    vector<vector<string>> res;

    void init(int n) {
        c1.clear();
        c2.clear();
        c3.clear();
        c4.clear();
        q.clear();
        num = n;
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
        dfs(0, 0);
        return res;
    }

    void dfs(int x, int y) {
        if (x == num) {
            res.push_back(q);
            return;
        }

        for (int j = 0; j < num; j++) {
            if (check(x, j)) {
                mark(x, j);
                dfs(x+1, 0);
                unmark(x, j);
            }
        }
    }

    void mark(int x, int y) {
        c1[x] = 1;
        c2[y] = 1;
        c3[y-x+num] = 1;
        c4[x+y] = 1;
        q[x][y] = 'Q';
        marked += 1;
    }

    void unmark(int x, int y) {
        c1[x] = 0;
        c2[y] = 0;
        c3[y-x+num] = 0;
        c4[x+y] = 0;
        q[x][y] = '.';
        marked -= 1;
    }

    bool check(int x, int y) {
        return c1[x] == 0 && c2[y] == 0 && c3[y-x+num] == 0 && c4[x+y] == 0;
    }
};
