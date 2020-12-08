// CreateTime: 2020-12-05 02:47:23
class Solution {
public:
    typedef pair<int, int> PII;

    vector<string> split(string &s, char x) {
        vector<string> ans;
        string sub = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != x) {
                sub.push_back(s[i]);
            }

            if (s[i] == x || i == s.size()-1) {
                ans.push_back(sub);
                sub = "";
            }
        }
        return ans;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);

        stack<PII> stk;
        for (int i = 0; i < logs.size(); i++) {
            auto x = logs[i];
            auto parsed = split(x, ':');

            auto id = stoi(parsed[0]);
            auto isStart = (parsed[1] == "start");
            auto time = stoi(parsed[2]);

            if (isStart) {
                stk.push({id, time});
            } else {
                auto top = stk.top();
                stk.pop();

                int diff = time - top.second + 1;
                ans[id] += diff;

                if (stk.size()) {
                    auto topId = stk.top().first;
                    ans[topId] -= diff;
                }
            }
        }

        return ans;
    }
};
