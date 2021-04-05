// CreateTime: 2021-04-04 10:41:34
class Solution {
public:
    typedef long long LL;

    const int MOD = 1e9+7;

    int maxDiffVal = INT_MIN;
    int maxDiffIdx = -1;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();

        LL S = 0;
        for (int i = 0; i < len; i++) {
            int diff = abs(nums1[i]-nums2[i]);
            S = (S + diff) % MOD;
            
            if (diff > maxDiffVal) {
                maxDiffVal = diff;
                maxDiffIdx = i;
            }
        }

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
        if (maxDiffVal < diff || maxDiffIdx == -1) {
            return false;
        }

        int len = nums1.size();

        auto to1 = nums2[maxDiffIdx]-(maxDiffVal-diff);
        auto to2 = nums2[maxDiffIdx]+(maxDiffVal-diff);

        for (int i = 0; i < len; i++) {
            if (to1 <= nums1[i] && nums1[i] <= to2) {
                return true;
            }
        }
        return false;
    }
};