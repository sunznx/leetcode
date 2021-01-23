// CreateTime: 2021-01-23 13:40:11
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int m = jobs.size();

        vector<int> sum(1<<m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < (1<<m); j++) {
                if ((j & (1<<i)) != 0) {
                    sum[j] += jobs[i];
                }
            }
        }

        auto l = 0;
        auto r = accumulate(jobs.begin(), jobs.end(), 0);

        while (l < r) {
            int m = (l+r) / 2;
            if (check(jobs, sum, k, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }

    bool check(vector<int> &jobs, vector<int> &sum, int k, int x) {
        int m = jobs.size();

        vector<int> f((1<<m), INT_MAX/2);
        f[0] = 0;

        for (int j = 0; j < (1<<m); j++) {
            for (int s = j; s > 0; s = ((s-1)&j)) {
                if (sum[s] <= x) {
                    f[j] = min(f[j], f[j-s]+1);
                }
            }
        }

        return f[(1<<m)-1] <= k;
    }
};
