// CreateTime: 2021-04-30 12:19:31
class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> m;

    bool isScramble(string s1, string s2) {
        if (m.find(s1) != m.end() && m[s1].find(s2) != m[s1].end()) {
            return m[s1][s2];
        }

        if (s1 == s2) {
            return m[s1][s2] = true;
        }

        string S1 = s1;
        string S2 = s2;

        sort(S1.begin(), S1.end());
        sort(S2.begin(), S2.end());

        if (S1 != S2) {
            return m[s1][s2] = false;
        }

        for (int i = 1; i < s1.size(); i++) {
            auto a = s1.substr(0, i);
            auto b = s1.substr(i);

            auto c = s2.substr(0, i);
            auto d = s2.substr(i);

            auto e = s2.substr(s2.size()-i);
            auto f = s2.substr(0, s2.size()-i);

            if (isScramble(a, c) && isScramble(b, d)) {
                return m[s1][s2] = true;
            }
            if (isScramble(a, e) && isScramble(b, f)) {
                return m[s1][s2] = true;
            }
        }
        return m[s1][s2] = false;
    }
};
