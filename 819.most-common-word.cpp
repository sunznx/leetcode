// CreateTime: 2019-12-06 01:04:08
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        auto arr = split(paragraph, " ,");
        unordered_map<string, int> m;
        unordered_set<string> b;

        for (auto &str: banned) {
            b.insert(str);
        }


        int maxn = 0;
        string res = "";
        for (auto &str: arr) {
            str = normal(str);
            if (b.find(str) != b.end()) {
                continue;
            }

            if (++m[str] > maxn) {
                res = str;
                maxn = m[str];
            }
        }
        return res;
    }

    string & normal(string &s) {
        int len = s.size();
        while (
            s[len-1] == '!' ||
            s[len-1] == '?' ||
            s[len-1] == '\'' ||
            s[len-1] == ',' ||
            s[len-1] == ';' ||
            s[len-1] == '.'
            ) {
            s.pop_back();
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    vector<string> split(string &s, string delims) {
        vector<string> res;

        unordered_set<char> m;
        for (auto &d: delims) {
            m.insert(d);
        }


        int k = 0;
        string v;
        int len = s.size();
        while (k < len || v.size() > 0) {
            if ((k == len || m.find(s[k]) != m.end()) && v.size() > 0) {
                res.push_back(v);
                v = "";
            } else if (m.find(s[k]) == m.end()) {
                v.push_back(s[k]);
            }
            k++;
        }

        return res;
    }
};
