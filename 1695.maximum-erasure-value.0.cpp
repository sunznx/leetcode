// CreateTime: 2021-01-17 17:56:47
class Solution {
public:
    int ans = 0;
    unordered_map<int, int> m;

    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto x = nums[i];
            s += x;
            m[x]++;

            while (m[x] > 1) {
                auto y = nums[l++];
                s -= y;
                m[y]--;
            }

            ans = max(ans, s);
        }

        return ans;
    }
};
