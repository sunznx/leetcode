// CreateTime: 2019-11-28 16:54:02
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int k = 0;
        int dash = 0;

        reverse(S.begin(), S.end());
        while (k+dash < S.size()) {
            if (S[k+dash] == '-') {
                S.erase(S.begin()+k+dash);
            } else {
                S[k+dash] = toupper(S[k+dash]);
                if (k > 0 && (k) % K == 0) {
                    S.insert(S.begin()+k+dash, '-');
                    dash += 1;
                }
                k++;
            }
        }
        reverse(S.begin(), S.end());
        return S;
    }
};
