// CreateTime: 2021-03-15 20:07:50
class Solution {
public:
    int ans = 0;
    int countSubstrings(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            tryExpand(s, i, i);
            tryExpand(s, i, i+1);
        }

        return ans;
    }

    void tryExpand(string &s, int k1, int k2) {
        int l = 0;
        int r = s.size()-1;

        while (l <= k1 && k1 <= r && l <= k2 && k2 <= r && s[k1] == s[k2]) {
            k1--;
            k2++;
            ans++;
        }
    }
};
