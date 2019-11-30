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

        int a;
        int b;
        int res;

        for (int t = 0; t <= k; t++) {
            if (i == len1) {
                a = 0x3fffffff;
            } else {
                a = nums1[i];
            }
            if (j == len2) {
                b = 0x3fffffff;
            } else {
                b = nums2[j];
            }

            if (a < b) {
                res = a;
                i++;
            } else {
                res = b;
                j++;
            }
        }
        return res;
    }
};
