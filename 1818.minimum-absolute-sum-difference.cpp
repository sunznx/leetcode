// CreateTime: 2021-04-04 10:41:34
class Solution {
public:
    typedef long long LL;

    const int MOD = 1e9+7;

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();

        LL S = 0;
        for (int i = 0; i < len; i++) {
            S = (S + D(nums1, nums2, i));
        }

        vector<int> SA = nums1;
        sort(SA.begin(), SA.end());

        int maxDiff = 0;
        for (int i = 0; i < len; i++) {
            auto x = nums2[i];
            auto iter = upper_bound(SA.begin(), SA.end(), x);
            int k = distance(SA.begin(), iter);

            int d;
            if (k == 0) {
                d = D(nums1, nums2, i)-abs(SA[0]-x);
            } else if (k == len) {
                d = D(nums1, nums2, i)-abs(SA[len-1]-x);
            } else {
                d = D(nums1, nums2, i)-min(abs(SA[k]-x), abs(SA[k-1]-x));
            }
            maxDiff = max(maxDiff, d);
        }
        return (S-maxDiff) % MOD;
    }

    int D(vector<int>& nums1, vector<int>& nums2, int k) {
        return abs(nums1[k]-nums2[k]);
    }
};