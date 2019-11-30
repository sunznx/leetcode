// CreateTime: 2019-11-30 16:19:59
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int len = (len1 + len2);
        if (len % 2 == 1) {
            int k = len/2;
            return findK1(nums1, nums2, k);
        }

        int k = len/2-1;
        return findK2(nums1, nums2, k);
    }

    double findK1(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        int j = 0;

        int a;
        int b;
        double res;

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

    double findK2(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0;
        int j = 0;

        int a;
        int b;
        int res;
        int res1;
        int res2;

        for (int t = 0; t <= k+1; t++) {
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

            if (t == k) {
                res1 = res;
            }
            if (t == k+1) {
                res2 = res;
            }
        }
        return (double)(res1 + res2) / 2;
    }
};
