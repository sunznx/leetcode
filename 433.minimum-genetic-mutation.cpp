// CreateTime: 2019-11-22 16:27:13
class Solution {
public:
    void bfs(queue<string> &q, unordered_map<string, int> &m, unordered_set<string>& s, string &end) {
        while (!q.empty()) {
            auto str = q.front();
            q.pop();

            auto changableStrs = getChangableStrings(s, str);
            for (int i = 0; i < changableStrs.size(); i++) {
                if (m.find(changableStrs[i]) == m.end()) {
                    m[changableStrs[i]] = m[str] + 1;
                    q.push(changableStrs[i]);
                }

                if (changableStrs[i] == end) {
                    return;
                }
            }
        }
    }

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        unordered_map<string, int> m;
        queue<string> q;
        for (int i = 0; i < bank.size(); i++) {
            s.insert(bank[i]);
        }

        m[start] = 0;
        q.push(start);
        bfs(q, m, s, end);

        if (m.find(end) != m.end()) {
            return m[end];
        }
        return -1;
    }

    vector<string> getChangableStrings(unordered_set<string>& s, string &str) {
        vector<string> res;

        char c;
        char d[4] = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < str.size(); i++) {
            c = str[i];

            for (int k = 0; k < 4; k++) {
                str[i] = d[k];

                if (s.find(str) != s.end()) {
                    res.push_back(str);
                }
            }

            str[i] = c;
        }

        return res;
    }
};

