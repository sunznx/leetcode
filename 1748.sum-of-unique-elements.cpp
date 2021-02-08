// CreateTime: 2021-02-06 22:32:06
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> m;
        for (auto &x: nums) {
            m[x]++;
        }

        for (auto &x: m) {
            if (x.second == 1) {
                ans += x.first;
            }
        }
        return ans;
    }
};