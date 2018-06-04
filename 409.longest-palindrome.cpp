class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        sort(s.begin(), s.end());
        
        bool ok = true;
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i-1] && ok) {
                ok = false;
                res += 2;
            } else {
                ok = true;
            }
        }
        
        return min(res+1, len);        
    }
};
