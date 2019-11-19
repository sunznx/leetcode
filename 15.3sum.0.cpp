class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int target = -nums[i];

            int j = i + 1;
            int k = len-1;

            while (k >= j+1) {
                int s = nums[j] + nums[k];
                if (j > i+1 && nums[j] == nums[j-1]) {
                    j++;
                    continue;
                }
                if (k < len-1 && nums[k] == nums[k+1]) {
                    k--;
                    continue;
                }

                if (s == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (s < target) {
                    j++;
                } else if (s > target) {
                    k--;
                }
            }
        }

        return res;
    }
};