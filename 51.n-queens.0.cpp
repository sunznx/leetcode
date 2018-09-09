class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> v1(2*n, 0);
        vector<int> v2(2*n, 0);
        vector<int> v3(2*n, 0);
        vector<int> arr(n, 0);
        dfs(v1, v2, v3, arr, n, 0);
        return res;
    }

    void dfs(vector<int> &v1, vector<int> &v2, vector<int> &v3, vector<int> &arr, int n, int step) {
        if (step == n) {
            vector<string> item(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                item[i][arr[i]] = 'Q';
            }
            res.push_back(item);
            return;
        }

        for (int idx = 0; idx < n; idx++) {
            if (v1[idx] || v2[idx+step] || v3[idx-step+n]) {
                continue;
            }

            arr[step] = idx;
            v1[idx] = v2[idx+step] = v3[idx-step+n] = 1;
            dfs(v1, v2, v3, arr, n, step+1);
            v1[idx] = v2[idx+step] = v3[idx-step+n] = 0;
        }
    }
};
