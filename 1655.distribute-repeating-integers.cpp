// CreateTime: 2021-01-23 12:49:47
class Solution {
public:

    unordered_map<int, int> m;
    vector<int> counts;

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        for (auto &x: nums) {
            m[x]++;
        }

        for (auto &x: m) {
            counts.push_back(x.second);
        }

        int m = quantity.size();
        vector<int> sum(1<<m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1<<m); j++) {
                if ((j & (1<<i)) != 0) {
                    sum[j] += quantity[i];
                }
            }
        }

        int n = counts.size();
        vector<vector<bool>> f(n, vector<bool>((1<<m)));
        for (int i = 0; i < n; i++) {
            f[i][0] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1<<m); j++) {
                if (i > 0 && f[i-1][j] == true) {
                    f[i][j] = true;
                    continue;
                }

                for (int s = j; s > 0; s = ((s-1)&j)) {
                    auto prev = j-s;
                    bool prevOk = false;
                    if (i == 0) {
                        prevOk = (prev == 0);
                    } else {
                        prevOk = f[i-1][prev];
                    }

                    if (prevOk == false) {
                        continue;
                    }

                    if (sum[s] <= counts[i]) {
                        f[i][j] = true;
                        break;
                    }
                }
            }
        }

        return f[n-1][(1<<m)-1];
    }
};
