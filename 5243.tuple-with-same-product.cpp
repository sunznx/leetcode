// CreateTime: 2021-01-17 10:34:21
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                auto x = nums[i];
                auto y = nums[j];
                m[x*y]++;
            }
        }

        int ans = 0;
        for (auto &x: m) {
            auto k = x.second;
            ans += k * (k-1) / 2;
        }

        return ans * 8;
    }
};