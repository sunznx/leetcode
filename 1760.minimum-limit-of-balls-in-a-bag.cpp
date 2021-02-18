// CreateTime: 2021-02-18 11:33:20
class Solution {
public:
    typedef long long LL;

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int m = (l+r) / 2;

            if (check(nums, maxOperations, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }

        return l;
    }

    bool check(vector<int>& nums, int maxOperations, int k) {
        LL ans = 0;
        for (auto &x: nums) {
            if (x % k == 0) {
                ans += x / k - 1;
            } else {
                ans += x / k;
            }
        }

        return ans <= maxOperations;
    }
};
