// CreateTime: 2021-01-17 10:34:21
class Solution {
public:
    typedef pair<int, int> PII;
    unordered_map<int, vector<PII>> m;

    int ans = 0;

    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                auto x = nums[i];
                auto y = nums[j];
                m[x*y].push_back({i, j});
            }
        }

        for (auto &x: m) {
            auto k = x.second.size();
            ans += k * (k-1) / 2 * 8;
        }

        return ans;
    }
};