// CreateTime: 2019-12-13 09:38:22
class Solution {
public:
    string removeOuterParentheses(string S) {
        int k = 0;
        int removed = 0;
        int left = 0;
        int len = S.size();
        while (k < len) {
            if (S[k] == '(' && removed == 0) {
                S.erase(S.begin() + k);
                removed++;
                len--;
            } else if (S[k] == '(') {
                k++;
                left++;
            } else if (S[k] == ')' && left) {
                k++;
                left--;
            } else if (S[k] == ')' && removed) {
                S.erase(S.begin() + k);
                removed--;
                len--;
            } else {
                k++;
            }
        }
        return S;
    }
};
