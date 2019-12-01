// CreateTime: 2019-11-30 23:07:37
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();

        unordered_map<int, vector<pair<int, int>>> m1;
        unordered_map<int, vector<pair<int, int>>> m2;

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

                for (int k = j+1; k < len; k++) {
                    if (k > j+1 && nums[k] == nums[k-1]) {
                        continue;
                    }

                    for (int l = k+1; l < len; l++) {
                        if (l > k+1 && nums[l] == nums[l-1]) {
                            continue;
                        }

                        int a = nums[i];
                        int b = nums[j];
                        int c = nums[k];
                        int d = nums[l];

                        if (a+b+c == target-d) {
                            res.push_back({a, b, c, d});
                        }
                    }
                }
            }
        }
        return res;
    }
};
