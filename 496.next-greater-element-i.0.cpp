// CreateTime: 2020-01-18 02:10:44
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<int> res(len1, -1);
        for (int i = 0; i < len1; i++) {
            int found = -1;
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    found = j;
                    break;
                }
            }

            if (found != -1) {
                for (int j = found+1; j < len2; j++) {
                    if (nums2[j] > nums1[i]) {
                        res[i] = nums2[j];
                        break;
                    }
                }
            }
        }

        return res;
    }
};
