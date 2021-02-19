// CreateTime: 2021-02-19 10:44:37
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l < r) {
            int m = (l+r) / 2;
            if (check(weights, D, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }

    inline bool check(vector<int>& weights, int D, int k) {
        int ans = 0;

        auto leaves = 0;
        for (auto &x: weights) {
            if (x > leaves) {
                leaves = k-x;
                ans++;
            } else {
                leaves = leaves-x;
            }
        }

        return ans <= D;
    }
};
