// CreateTime: 2019-12-05 21:59:55
class Solution {
public:
    string removeVowels(string S) {
        int k = 0;
        
        while (k < S.size()) {
            if (S[k] == 'a' || S[k] == 'e' || S[k] == 'i' || S[k] == 'o' || S[k] == 'u') {
                S.erase(S.begin()+k);
            } else {
                k++;
            }
        }
        
        return S;
    }
};
