// CreateTime: 2020-11-30 08:11:50
class Solution {
public:
    string reorganizeString(string S) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
        vector<int> m(256);

        for (int i = 0; i < S.size(); i++) {
            char x = S[i];
            m[x]++;
        }

        for (int x = 0; x < m.size(); x++) {
            if (m[x] > 0) {
                q.push({m[x], x});
            }
        }

        string ans;

        while (q.size() >= 2) {
            auto top1 = q.top();
            q.pop();

            auto top2 = q.top();
            q.pop();

            auto x1 = top1.second;
            auto x2 = top2.second;

            ans.push_back(x1);
            ans.push_back(x2);

            m[x1]--;
            m[x2]--;

            if (m[x1] > 0) {
                q.push({m[x1], x1});
            }

            if (m[x2] > 0) {
                q.push({m[x2], x2});
            }
        }

        if (q.size()) {
            auto top = q.top();
            q.pop();

            auto x = top.second;
            if (m[x] == 1) {
                ans.push_back(x);
            } else {
                return "";
            }
        }

        return ans;
    }
};
