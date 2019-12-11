// CreateTime: 2019-12-11 11:15:35
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0 || words[0].size() == 0) {
            return res;
        }

        unordered_map<string, int> m;
        for (auto &word: words) {
            m[word] += 1;
        }

        int len = s.size();
        int e = words[0].size();
        int k = words.size();

        for (int i = 0; i <= len-k*e; i++) {
            if (check(s, m, i, e, k)) {
                res.push_back(i);
            }
        }
        return res;
    }

    bool check(string &s, unordered_map<string, int> &m, int idx, int e, int k) {
        unordered_map<string, int> c;
        int eq = 0;

        for (int i = 0; i < k; i++) {
            string sub = s.substr(idx+i*e, e);
            c[sub] += 1;

            if (m.find(sub) == m.end()) {
                return false;
            }

            if (c[sub] > m[sub]) {
                return false;
            }

            if (c[sub] == m[sub]) {
                eq += 1;
            }
        }

        return eq == m.size();
    }
};
