// CreateTime: 2021-02-20 22:36:23
class Solution {
public:
    string longestNiceSubstring(string s) {
        int len = s.size();

        string ans = "";

        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (check(s, i, j) && j-i+1 > ans.size()) {
                    ans = s.substr(i, j-i+1);
                }
            }
        }

        return ans;
    }

    bool check(string &s, int i, int j) {
        vector<bool> m1(26);
        vector<bool> m2(26);
        for (int k = i; k <= j; k++) {
            auto x = s[k];
            if ('a' <= x && x <= 'z') {
                m1[x-'a'] = true;
            } else {
                m2[x-'A'] = true;
            }
        }

        for (int x = 0; x < 26; x++) {
            if (!(m1[x] == true && m2[x] == true || m1[x] == false && m2[x] == false)) {
                return false;
            }
        }
        return true;
    }
};