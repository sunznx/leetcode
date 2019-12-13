// CreateTime: 2019-12-13 09:38:22
class Solution {
public:
    string removeOuterParentheses(string S) {
        int k = 0;
        int removed = 0;
        int left = 0;
        while (k < S.size()) {
            if (S[k] == '(' && removed == 0) {
                S.erase(S.begin() + k);
                removed++;
            } else if (S[k] == '(') {
                k++;
                left += 1;
            } else if (S[k] == ')' && left) {
                k++;
                left--;
            } else if (S[k] == ')' && left == 0 && removed) {
                S.erase(S.begin() + k);
                removed--;
            } else {
                k++;
            }
        }
        return S;
    }
};
