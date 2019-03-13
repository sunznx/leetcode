class Solution {
public:
    int n;
    int res;
    vector<int> c1;
    vector<int> c2;
    vector<int> c3;
    vector<int> c4;

    void init(int num) {
        res = 0;
        n = num;
        
        for (int i = 0; i < 2*n; i++) {
            c1.push_back(0);
            c2.push_back(0);
            c3.push_back(0);
            c4.push_back(0);
        }
    }
    
    void mark(int x, int y) {
        c1[x] = 1;
        c2[y] = 1;
        c3[x-y+n] = 1;
        c4[x+y] = 1;
    }
    
    void unmark(int x, int y) {
        c1[x] = 0;
        c2[y] = 0;
        c3[x-y+n] = 0;
        c4[x+y] = 0;
    }

    bool check(int x, int y) {
        return c1[x] == 0 && c2[y] == 0 && c3[x-y+n] == 0 && c4[x+y] == 0;
    }

    int totalNQueens(int n) {
        init(n);
        dfs(0);
        return res;
    }
    
    void dfs(int x) {
        if (x == n) {
            res += 1;
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
};
