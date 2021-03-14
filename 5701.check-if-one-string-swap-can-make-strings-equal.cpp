// CreateTime: 2021-03-14 10:31:06
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int d1 = -1;
        int d2 = -1;

        int len = s1.size();
        if (s2.size() != len) {
            return false;
        }

        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i]) {
                if (d1 == -1) {
                    d1 = i;
                } else if (d2 == -1) {
                    d2 = i;
                } else {
                    return false;
                }
            }
        }

        if (d1 == -1 && d2 == -1) {
            return true;
        } else if (d1 == -1 || d2 == -1) {
            return false;
        }

        swap(s1[d1], s1[d2]);
        return s1 == s2;
    }
};