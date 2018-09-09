class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;

        vector<int> arr1(2*n, 0);
        vector<int> arr2(2*n, 0);
        vector<int> arr3(2*n, 0);
        vector<int> arr4(2*n, 0);
        vector<string> v(n, string(n, '.'));
        dfs(res, arr1, arr2, arr3, arr4, v, n, 0, 0);
        return res;
    }

    bool check(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3, vector<int> &arr4, int n, int x, int y) {
        return arr1[x] == 0 && arr2[y] == 0 && arr3[y-x+n] == 0 && arr4[x+y] == 0;
    }

    void add(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3, vector<int> &arr4, vector<string> &v, int n, int x, int y) {
        arr1[x] = 1;            // 行
        arr2[y] = 1;            // 列
        arr3[y-x+n] = 1;        // 斜
        arr4[x+y] = 1;          // 斜
        v[x][y] = 'Q';
    }

    void remove(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3, vector<int> &arr4, vector<string> &v, int n, int x, int y) {
        arr1[x] = 0;            // 行
        arr2[y] = 0;            // 列
        arr3[y-x+n] = 0;        // 斜
        arr4[x+y] = 0;          // 斜
        v[x][y] = '.';
    }

    void dfs(vector<vector<string>> &res, vector<int> &arr1, vector<int> &arr2, vector<int> &arr3, vector<int> &arr4, vector<string> v, int n, int x, int y) {
        if (x == n) {
            res.push_back(v);
            return;
        }

        for (int j = y; j < n; j++) {
            if (check(arr1, arr2, arr3, arr4, n, x, j)) {
                add(arr1, arr2, arr3, arr4, v, n, x, j);
                dfs(res, arr1, arr2, arr3, arr4, v, n, x+1, 0);
                remove(arr1, arr2, arr3, arr4, v, n, x, j);
            }
        }
    }
};
