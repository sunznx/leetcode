// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         reverse(nums.begin(), nums.end());
//         return nums[k-1];
//     }
// };


class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    int partition(vector<int>& nums, int l, int r) {
        int x = nums[r];
        int i = l;
        int j = r-1;
        while (i <= j) {
            if (nums[i] >= x) {
                i++;
            } else {
                swap(nums, i, j);
                j--;
            }
        }
        swap(nums, i, r);
        return i;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0;
        int r = len-1;
        while (l <= r) {
            int p = partition(nums, l, r);
            if (p+1 == k) {
                return nums[p];
            }
            if (p+1 > k) {
                r = p-1;
            } else {
                l = p+1;
            }
        }
    }
};


