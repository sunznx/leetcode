class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res = {0, 1};

        int tot = nums.size();

        for (int i = 0; i < tot-1; i++) {
            for (int j = i+1; j < tot; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }

        return res;

    }
};
