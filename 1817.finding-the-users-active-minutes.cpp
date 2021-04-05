// CreateTime: 2021-04-04 10:33:13
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int, unordered_set<int>> S;

        for (auto &x: logs) {
            auto id = x[0];
            auto time = x[1]-1;

            S[id].insert(time);
        }

        for (auto &x: S) {
            auto s = x.second;
            ans[s.size()-1]++;
        }
        return ans;
    }
};