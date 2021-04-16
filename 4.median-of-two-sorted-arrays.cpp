// CreateTime: 2019-11-30 16:19:59
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int len = (len1 + len2);
        if (len % 2 == 1) {
            int k = len/2;
            return (double)findK(nums1, nums2, k);
        }
        int k1 = len/2;
        int k2 = len/2-1;
        return (double) (findK(nums1, nums2, k1) + findK(nums1, nums2, k2)) / 2;
    }

    int findK(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        int j = 0;

        int res;

        for (int t = 0; t <= k; t++) {
            if (i == len1) {
                res = nums2[j++];
            } else if (j == len2) {
                res = nums1[i++];
            } else if (nums1[i] <= nums2[j]) {
                res = nums1[i++];
            } else {
                res = nums2[j++];
            }
        }
        return res;
    }
};
