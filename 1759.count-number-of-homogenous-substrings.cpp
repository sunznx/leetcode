// CreateTime: 2021-02-14 02:35:13
class Solution {
public:
    typedef long long LL;

    const int MOD = 1e9+7;
    LL ans = 0;
    LL count = 0;

    int countHomogenous(string s) {
        for (int i = 0; i < s.size(); i++) {
            count++;
            if (i == s.size()-1 || s[i] != s[i+1]) {
                ans += ((count+1) * count / 2) % MOD;
                count = 0;
            }
        }

        return (int)(ans);
    }
};