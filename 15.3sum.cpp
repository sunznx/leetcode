class Solution {
public:
    bool find(int from, vector<int>& nums, int v) {
        int len = nums.size();

        int l = from;
        int r = len-1;
        while (l < r) {
            int mid = (l+r) / 2;
            if (v <= nums[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l <= len-1 && nums[l] == v;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j = i+1; j < len; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int x = nums[i];
                int y = nums[j];
                int z = - (x+y);

                if (find(j+1, nums, z)) {
                    res.push_back({x, y, z});
                }
            }
        }

        return res;
    }
};