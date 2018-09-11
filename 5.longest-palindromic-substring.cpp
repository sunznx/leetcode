class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxn = 0;
        
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (len-i <= maxn) {
                break;
            }
            for (int j = len-1; j >= i; j--) {
                int sublen = j-i+1;
                if (sublen <= maxn) {
                    break;
                }
                string substr = s.substr(i, sublen);
                if (sublen > maxn && isPalindrome(substr)) {
                    maxn = sublen;
                    res = substr;
                    break;
                }
            }
        }
        
        return res;
    }
    
    bool isPalindrome(string s) {
        int len = s.size();
        for (int i = 0; i <= len/2; i++) {
            if (s[i] != s[len-1-i]) {
                return false;
            }
        }
        
        return true;
    }
};
