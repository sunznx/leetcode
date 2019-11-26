// CreateTime: 2019-11-26 16:55:45
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> m;
        unordered_map<int, int> c;

        string s;

        int len = str.size();
        int p = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] != ' ') {
                s += str[i];
            }

            if (str[i] == ' ' || i == len-1) {
                if (m[s] == 0 && c[pattern[p]] == 0) {
                    m[s] = pattern[p];
                    c[pattern[p]] += 1;
                } else if (c[pattern[p]] == 0 && m[s] != 0) {
                    return false;
                } else if (m[s] == 0 && c[pattern[p]] != 0) {
                    return false;
                } else if (c[pattern[p]] != 0 && m[s] != pattern[p]) {
                    return false;
                }

                s = "";
                p += 1;
            }
        }
        return p == pattern.size();
    }
};
