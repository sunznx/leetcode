// CreateTime: 2019-12-11 17:39:43
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        int len = s1.size();

        auto ss1 = s1;
        auto ss2 = s2;
        sort(ss1.begin(), ss1.end());
        sort(ss2.begin(), ss2.end());
        if (ss1 != ss2) {
            return false;
        }

        for (int i = 1; i < len; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size()-i)) && isScramble(s1.substr(i), s2.substr(0, s2.size()-i))) {
                return true;
            }
        }

        return false;
    }
};
