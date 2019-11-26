// CreateTime: 2019-11-27 00:23:57
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();

        auto sorted = nums;
        sort(sorted.begin(), sorted.end());

        int l = 0;
        while (l < len && nums[l] == sorted[l]) {
            l += 1;
        }

        int r = 0;
        while (r < len && nums[len-1-r] == sorted[len-1-r]) {
            r++;
        }

        return max(0, len-(l+r));
    }
};
