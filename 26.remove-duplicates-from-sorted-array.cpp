class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int len = nums.size();
        int res = len;
        for (int i = 0; i < len-1;) {
            if (nums[i] == nums[i+1]) {
                res--;
                int t = nums[i+1];
                for (int k = i+1; k < len-1; k++) {
                    nums[k] = nums[k+1];
                }
                nums[len-1] = t;
                len--;
            } else {
                i++;
            }
        }

        return res;
    }
};

