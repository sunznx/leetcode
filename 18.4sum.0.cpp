// CreateTime: 2019-11-30 23:07:37
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();

        unordered_map<int, vector<pair<int, int>>> m;

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int j = len-1; j >= 0; j--) {
            if (j < len-1 && nums[j] == nums[j+1]) {
                continue;
            }

            for (int i = j-1; i >= 0; i--) {
                if (i < j-1 && nums[i] == nums[i+1]) {
                    continue;
                }

                int a = nums[i];
                int b = nums[j];
                m[a+b].push_back({i, j});
            }
        }

        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            for (int j = i+1; j < len; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }

                int a = nums[i];
                int b = nums[j];
                for (auto item: m[target-(a+b)]) {
                    int k = item.first;
                    int l = item.second;

                    if (k > j) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                    }
                }

            }
        }

        return res;
    }
};
