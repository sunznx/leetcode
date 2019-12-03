class Solution {
public:
    int res;

    int totalNQueens(int n) {
        res = 0;
        vector<int> v(n, 0);
        vector<int> arr(n, 0);
        dfs(arr, n, 0);
        return res;
    }

    void dfs(vector<int> &arr, int n, int step) {
        if (step == n) {
            res += 1;
            return;
        }

        for (int idx = 0; idx < n; idx++) {
            if (check(arr, step, idx)) {
                arr[step] = idx;
                dfs(arr, n, step+1);
            }
        }
    }

    bool check(vector<int> &arr, int step, int idx) {
        for (int i = 0; i < step; i++) {
            if (arr[i] == idx || i + arr[i] == step+idx || i-arr[i] == step-idx) {
                return false;
            }
        }
        return true;
    }
};
