// CreateTime: 2021-01-23 19:48:04
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (auto &x: nums) {
            freq[x]++;
        }

        vector<int> counts;
        for (auto &x: freq) {
            counts.push_back(x.second);
        }

        auto n = counts.size();
        auto m = quantity.size();

        vector<int> sum(1<<m);
        for (int i = 0; i < (1<<m); i++) {
            for (int j = 0; j < m; j++) {
                if ((i&(1<<j)) != 0) {
                    sum[i] += quantity[j];
                }
            }
        }

        vector<vector<bool>> f(n, vector<bool>(1<<m));
        for (int i = 0; i < n; i++) {
            f[i][0] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1<<m); j++) {
                if (i > 0 && f[i-1][j]) {
                    f[i][j] = true;
                    continue;
                }

                for (int s = j; s > 0; s = ((s-1)&j)) {
                    auto prev = (j-s);
                    auto prevOk = false;
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
