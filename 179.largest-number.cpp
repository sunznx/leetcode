// CreateTime: 2021-04-12 00:38:19
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const auto &a, const auto &b) {
            string s1 = to_string(a);
            string s2 = to_string(b);

            return (s1+s2) > (s2+s1);
        });

        string ans = "";
        for (auto &x: nums) {
            ans += to_string(x);
        }
        while (ans.size() >= 2 && ans[0] == '0') {
            ans.erase(ans.begin());
        }
        return ans;
    }
};
