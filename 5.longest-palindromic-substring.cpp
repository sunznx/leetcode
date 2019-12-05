// CreateTime: 2019-12-04 12:47:08
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();

        string res = "";

        for (int k = 0; k < len; k++) {
            int l;

            l = 0;
            while (k-l >= 0 && k+l <= len-1 && s[k-l] == s[k+l]) {
                auto sz = (k+l) - (k-l) + 1;
                if (sz > res.size()) {
                    res = s.substr(k-l, sz);
                }
                l++;
            }

            l = 0;
            while (k-l >= 0 && k+1+l <= len-1 && s[k-l] == s[k+1+l]) {
                auto sz = (k+1+l) - (k-l) + 1;
                if (sz > res.size()) {
                    res = s.substr(k-l, sz);
                }
                l++;
            }
        }

        return res;
    }
};