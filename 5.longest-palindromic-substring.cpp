// CreateTime: 2021-03-01 19:28:31
class Solution {
public:
    string ans = "";

    string longestPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            tryExpand(s, i, i);
            tryExpand(s, i, i+1);
        }
        return ans;
    }

    void tryExpand(string &s, int k1, int k2) {
        int len = s.size();
        while (0 <= k1 && k1 <= s.size()-1 && 0 <= k2 && k2 <= s.size()-1 && s[k1] == s[k2]) {
            int sz = k2-k1+1;
            if (sz > ans.size()) {
                ans = s.substr(k1, sz);
            }

            k1--;
            k2++;
        }
    }
};
