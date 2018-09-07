class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());
        
        int ans = 0;
        int len = s.size();
        int i = 1;
        while (i < len) {
            if (s[i] == s[i-1]) {
                ans += 2;
                i += 2;
            } else {
                i += 1;
            }
        }
        
        if (len - ans > 0) {
            ans += 1;
        }
        
        return ans;
    }
};
