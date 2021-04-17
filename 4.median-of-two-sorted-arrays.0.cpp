// CreateTime: 2021-04-16 17:25:46
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int len = len1+len2;

        if (len % 2 == 1) {
            int k = len/2;
            return (double)findK(nums1, nums2, k+1);
        }

        int k1 = len/2;
        int k2 = len/2+1;
        return (double)(findK(nums1, nums2, k1) + findK(nums1, nums2, k2)) / 2;
    }

    int findK(vector<int>& nums1, vector<int>& nums2, int k, int l1 = 0, int l2 = 0) {
        if (l1 == nums1.size()) {
            return nums2[l2+k-1];
        }
        if (l2 == nums2.size()) {
            return nums1[l1+k-1];
        }

        if (k == 1) {
            return min(nums1[l1], nums2[l2]);
        }

        int s = k/2;
        int k1 = min(l1+s-1, (int)nums1.size()-1);
        int k2 = min(l2+s-1, (int)nums2.size()-1);
        if (nums1[k1] <= nums2[k2]) {
            int s1 = k1-l1+1;
            return findK(nums1, nums2, k-s1, k1+1, l2);
        }

        int s2 = k2-l2+1;
        return findK(nums1, nums2, k-s2, l1, k2+1);
    }
};
