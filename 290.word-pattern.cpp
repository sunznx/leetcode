// CreateTime: 2019-11-26 16:55:45
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> m;
        unordered_map<int, string> c;

        string s;

        int len = str.size();
        int p = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] != ' ') {
                s += str[i];
            }

            if (str[i] == ' ' || i == len-1) {
                auto idx = pattern[p];
                if (m[s] == 0 && c[idx] == "") {
                    m[s] = idx;
                    c[idx] = s;
                } else if (c[idx] == "" && m[s] != 0) {
                    return false;
                } else if (m[s] == 0 && c[idx] != "") {
                    return false;
                } else if (c[idx] != s && m[s] != idx) {
                    return false;
                }

                s = "";
                p += 1;
            }
        }
        return p == pattern.size();
    }
};
