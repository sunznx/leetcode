class Solution {
public:
    void sort(vector<int>& nums) {
        int len = nums.size();
        sort(nums, 0, len-1);
    }

    void sort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }

        int m = (l+r) / 2;
        sort(nums, l, m);
        sort(nums, m+1, r);
        merge(nums, l, r);
    }

    void merge(vector<int> &nums, int l, int r) {
        int len = nums.size();
        int m = (l+r) / 2;

        int i = l;
        int j = m+1;

        vector<int> aux(len);

        for (int t = l; t <= r; t++) {
            aux[t] = nums[t];
        }

        for (int t = l; t <= r; t++) {
            if (j > r) {
                nums[t] = aux[i++];
            } else if (i > m) {
                nums[t] = aux[j++];
            } else if (aux[j] < aux[i]) {
                nums[t] = aux[j++];
            } else {
                nums[t] = aux[i++];
            }
        }
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        sort(nums1);
        sort(nums2);

        int i = 0;
        int j = 0;

        vector<int> res;

        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            }
        }

        return res;
    }
};
