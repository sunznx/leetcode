// CreateTime: 2021-01-23 20:00:02
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        auto m = jobs.size();
        vector<int> sum(1<<m);
        for (int i = 0; i < (1<<m); i++) {
            for (int j = 0; j < m; j++) {
                if ((i&(1<<j)) != 0) {
                    sum[i] += jobs[j];
                }
            }
        }

        auto l = *max_element(jobs.begin(), jobs.end());
        auto r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = (l+r) / 2;
            if (check(jobs, sum, k, mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }

    bool check(vector<int> &jobs, vector<int> &sum, int k, int x) {
        auto m = jobs.size();

        vector<int> f((1<<m), INT_MAX/2);
        f[0] = 0;

        for (int i = 0; i < (1<<m); i++) {
            for (int s = i; s > 0; s=((s-1)&i)) {
                if (sum[s] <= x) {
                    f[i] = min(f[i], f[i-s]+1);
                }
            }
        }

        return f[(1<<m)-1] <= k;
    }
};
