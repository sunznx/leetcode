// CreateTime: 2021-02-19 10:35:23
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int m = (l+r) / 2;

            if (check(piles, H, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }

    inline bool check(vector<int>& piles, int H, int k) {
        int ans = 0;

        for (auto &x: piles) {
            if (x % k == 0) {
                ans += x / k;
            } else {
                ans += x / k + 1;
            }
        }

        return ans <= H;
    }
};
