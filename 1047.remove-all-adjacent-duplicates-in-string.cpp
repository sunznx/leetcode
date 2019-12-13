// CreateTime: 2019-12-14 07:06:28
class Solution {
public:
    string removeDuplicates(string S) {
        int k = 0;
        while (k+1 < S.size()) {
            if (k+1 < S.size() && S[k] == S[k+1]) {
                S.erase(S.begin()+k+1);
                S.erase(S.begin()+k);
                k = max(0, k-1);
            } else {
                k++;
            }
        }
        return S;
    }
};
