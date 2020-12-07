// CreateTime: 2020-12-07 11:36:04
class Solution {
public:
    int scoreOfParentheses(string S) {
        int ans = 0;

        int base = 0;
        for (int i = 0; i < S.size(); i++) {
            auto x = S[i];

            if (x == '(') {
                base += 1;
            } else {
                base -= 1;

                if (S[i-1] == '(') {
                    ans += pow(2, base);
                }
            }
        }

        return ans;
    }
};
