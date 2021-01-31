// CreateTime: 2021-01-31 10:41:00
class Solution {
public:
    vector<int> ans;

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> m;

        int top;
        int size = 0;
        for (auto &item: adjacentPairs) {
            auto x = item[0];
            auto y = item[1];

            if (m.find(x) == m.end()) {
                size++;
            }

            if (m.find(y) == m.end()) {
                size++;
            }

            m[x].push_back(y);
            m[y].push_back(x);
        }

        for (auto &x: m) {
            if (x.second.size() == 1) {
                top = x.first;
                break;
            }
        }

        unordered_set<int> seen;

        ans.push_back(top);
        seen.insert(top);

        while (seen.size() != size) {
            for (auto &x: m[top]) {
                if (seen.find(x) == seen.end()) {
                    top = x;
                    ans.push_back(top);
                    seen.insert(top);
                }
            }
        }

        return ans;
    }
};