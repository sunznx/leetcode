// CreateTime: 2021-03-06 22:44:19
class Solution {
public:
    vector<int> arr;
    bool checkPowersOfThree(int n) {
        auto tot = (int)log(n);
        arr.resize(tot+1, 1);
        for (int i = 1; i <= tot; i++) {
            arr[i] = arr[i-1] * 3;
        }

        return dfs(n);
    }

    bool dfs(int n, int sub = 0, int step = 0) {
        if (sub == n) {
            return true;
        }

        if (sub > n || step >= arr.size()) {
            return false;
        }

        auto x = arr[step];
        return dfs(n, sub, step+1) || dfs(n, sub+x, step+1);
    }
};
