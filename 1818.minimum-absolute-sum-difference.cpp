// CreateTime: 2021-04-04 10:41:34
class Solution {
public:
    typedef long long LL;
    typedef pair<LL, int> PII;

    const int MOD = 1e9+7;

    vector<PII> d;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();

        d.resize(len);

        LL S = 0;
        for (int i = 0; i < len; i++) {
            d[i] = {abs(nums1[i] - nums2[i]), i};
            S = (S + d[i].first) % MOD;
        }

        sort(d.rbegin(), d.rend());

        LL l = 0;
        LL r = S;
        while (l < r) {
            LL m = (l+r) / 2;
            LL diff = abs(S - m);
            if (check(nums1, nums2, diff)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }

    bool check(vector<int>& nums1, vector<int>& nums2, LL diff) {
        int len = nums1.size();
        if (d[0].first < diff) {
            return false;
        }

        auto idx = d[0].second;

        auto to1 = nums2[idx]-(d[0].first-diff);
        auto to2 = nums2[idx]+(d[0].first-diff);

        for (int i = 0; i < len; i++) {
            if (to1 <= nums1[i] && nums1[i] <= to2) {
                return true;
            }
        }
        return false;
    }
};