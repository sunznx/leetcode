// CreateTime: 2020-12-08 11:35:15
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;

        int l = 0;
        int r = 0;
        int k = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                l++;
            } else {
                r++;
            }

            if (l == r) {
                ans += S.substr(k+1, l+r-2);
                l = 0;
                r = 0;
                k = i+1;
            }
        }
        return ans;
    }
};
