class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();

        vector<unsigned int> p(27);
        init(p);

        map<unsigned int, vector<string>> m;

        for (int i = 0; i < len; i++) {
            auto h = calcHash(p, strs[i]);

            auto item = m.find(h);
            if (item == m.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                m.insert(make_pair(h, v));
            } else {
                (item->second).push_back(strs[i]);
            }
        }

        vector<vector<string>> res;

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            int len = iter->second.size();

            vector<string> v;
            for (int i = 0; i < len; i++) {
                v.push_back((iter->second)[i]);
            }
            res.push_back(v);
        }
        return res;
    }

    void init(vector<unsigned int> &p) {
        int P = 131;
        p[0] = 1;
        for (int i = 1; i < p.size(); i++) {
            p[i] = p[i-1] * P;
        }
    }

    unsigned int calcHash(vector<unsigned int> &p, string &s) {
        unsigned int ans = 0;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            ans += p[s[i]-'a'];
        }

        return ans;
    }
};



