// CreateTime: 2020-12-08 07:51:55
class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;

        int l = 0;
        int r = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                l++;
            } else {
                r++;
            }

            if (r > l) {
                ans++;
                l++;
            }
        }

        return ans + abs(l-r);
    }
};
