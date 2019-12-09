class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        vector<int> m(52);

        for (int i = 0; i < len; i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                m[s[i]-'a'] += 1;
            } else {
                m[s[i]-'A'+26] += 1;                
            }
        }
        
        int res = 0;
        for (int i = 0; i < 52; i++) {
            res += m[i] / 2 * 2;
        }
        
        return min(res+1, len);        
    }
};
