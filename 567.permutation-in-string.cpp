class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        int res1[26];
        int res2[26];

        memset(res1, 0, sizeof(res1));
        memset(res2, 0, sizeof(res2));

        for (int i = 0; i < len1; i++) {
            res1[s1[i]-'a'] += 1;
        }
        for (int i = 0; i <= len2-len1; i++) {
            memset(res2, 0, sizeof(res2));
            for (int j = i; j < len1+i; j++) {
                res2[s2[j]-'a'] += 1;
            }


            bool ok = true;
            for (int x = 0; x < 26; x++) {
                if (res1[x] > res2[x]) {
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
