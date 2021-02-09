// CreateTime: 2021-02-09 10:53:20
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int sz = 1; sz <= s.size()/2; sz++) {
            if (s.size()%sz != 0) {
                continue;
            }

            bool ok = true;
            for (int k = 1; k < s.size()/sz; k++) {
                for (int j = 0; j < sz; j++) {
                    if (s[j] != s[k*sz+j]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) {
                    break;
                }
            }

            if (ok) {
                return true;
            }
        }

        return false;
    }
};