class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        vector<int> m(256);

        for (int i = 0; i < len; i++) {
            m[s[i]] += 1;
        }
        
        int res = 0;
        for (int i = 'A'; i <= 'Z'; i++) {
            res += m[i] / 2 * 2;
        }
        for (int i = 'a'; i <= 'z'; i++) {
            res += m[i] / 2 * 2;
        }
        
        return min(res+1, len);        
    }
};
