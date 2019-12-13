// CreateTime: 2019-12-13 20:43:34
class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0;
        int r = 0;

        int ans = 0;

        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == 'L') {
                l++;
            } else {
                r++;
            }
            
            if (l == r) {
                ans++;
            }
        }
        
        return ans;
    }
};
