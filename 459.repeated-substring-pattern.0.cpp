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
                cout << s.substr(0, sz) << " " << s.substr(k*sz, sz) << endl;
                if (s.substr(0, sz) != s.substr(k*sz, sz)) {
                    ok = false;
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