// CreateTime: 2021-02-28 10:54:13
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);

        if (s1 == s2) {
            return 0;
        }

        if (s1 < s2) {
            return minOperations(nums2, nums1);
        }

        sort(nums1.rbegin(), nums1.rend());
        sort(nums2.begin(), nums2.end());

        int diff = s1-s2;

        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        int ans = 0;
        while (diff > 0 && (i < len1 || j < len2)) {
            ans++;
            if (i == len1) {
                auto y = nums2[j++];
                int k2 = 6-y;
                diff -= k2;
            } else if (j == len2) {
                auto x = nums1[i++];
                int k1 = x-1;
                diff -= k1;
            } else {
                auto y = nums2[j];
                auto x = nums1[i];

                int k1 = x-1;
                int k2 = 6-y;

                if (k1 > k2) {
                    i++;
                    diff -= k1;
                } else {
                    j++;
                    diff -= k2;
                }
            }
        }

        if (diff <= 0) {
            return ans;
        }

        return -1;
    }
};