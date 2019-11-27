// CreateTime: 2019-11-27 12:35:34
class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.size();
        
        int l = 0;
        int r = len-1;
        
        while (l < r) {
            if (s[l] != s[r]) {
                return help(s, l+1, r)  || help(s, l, r-1);
            } else {
                l++;
                r--;
            }
        }
        
        return true;
    }
    
    bool help(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
};
