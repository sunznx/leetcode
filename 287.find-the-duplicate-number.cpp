class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size();

        while (l < r) {
            int m = (l+r) / 2;
            if (check(nums, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return (int)(l);
    }

    bool check(vector<int> &nums, int x) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= x) {
                count++;
            }
        }
        return count > x;
    }
};
