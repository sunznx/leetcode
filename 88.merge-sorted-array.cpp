// CreateTime: 2021-04-05 09:59:29
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m-1;
        int idx2 = n-1;
        for (int i = m+n-1; i >= 0; i--) {
            if (idx1 < 0) {
                nums1[i] = nums2[idx2--];
            } else if (idx2 < 0) {
                nums1[i] = nums1[idx1--];
            } else if (nums1[idx1] > nums2[idx2]) {
                nums1[i] = nums1[idx1--];
            } else {
                nums1[i] = nums2[idx2--];
            }
        }
    }
};
