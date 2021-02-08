// CreateTime: 2021-02-06 22:39:56
class Solution {
public:
    int minimumLength(string s) {
        int l = 0;
        int r = s.size()-1;

        while (l < r) {
            if (s[l] != s[r]) {
                break;
            }

            l++;
            r--;

            while (l <= r && s[l] == s[l-1]) {
                l++;
            }

            while (l <= r && s[r] == s[r+1]) {
                r--;
            }
        }

        return max(0, r-l+1);
    }
};
