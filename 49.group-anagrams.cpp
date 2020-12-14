// CreateTime: 2020-12-14 11:36:33
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();

        auto p = init();

        unordered_map<unsigned int, vector<string>> m;

        for (int i = 0; i < len; i++) {
            auto h = calcHash(p, strs[i]);
            m[h].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            auto x = iter->second;
            res.push_back(x);
        }
        return res;
    }

    vector<unsigned int> init() {
        vector<unsigned int> p(256);
        int P = 131;
        p[0] = 1;
        for (int i = 1; i < p.size(); i++) {
            p[i] = p[i-1] * P;
        }
        return p;
    }

    unsigned int calcHash(vector<unsigned int> &p, string &s) {
        unsigned int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            auto x = s[i];
            ans += p[x];
        }
        return ans;
    }
};