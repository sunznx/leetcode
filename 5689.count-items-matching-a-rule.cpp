// CreateTime: 2021-02-28 10:31:21
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (auto &x: items) {
            auto type = x[0];
            auto color = x[1];
            auto name = x[2];

            if (ruleKey == "type" && ruleValue == type) {
                ans++;
            }

            if (ruleKey == "color" && ruleValue == color) {
                ans++;
            }

            if (ruleKey == "name" && ruleValue == name) {
                ans++;
            }
        }

        return ans;
    }
};