class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v(k, 0);
        vector<int> arr(k, 0);
        dfs(v, arr, n, k, 0, 1);
        return res;
    }

    void dfs(vector<int> &v, vector<int> &arr, int n, int k, int step, int index) {
        if (step == k) {
            auto total = 0;
            for (int i = 0; i < k; i++) {
                if (arr[i]) {
                    total += arr[i];
                }
            }
            if (total == n) {
                res.push_back(arr);
            }
            return;
        }

        for (int i = index; i <= 9; i++) {
            arr[step] = i;
            dfs(v, arr, n, k, step+1, i+1);
        }
    }
};
