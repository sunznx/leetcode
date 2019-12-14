// CreateTime: 2019-12-14 13:12:24
class Solution {
public:
    bool canPermutePalindrome(string s) {
        sort(s.begin(), s.end());
        
        int k = 0;
        while (k+1 < s.size()) {
            if (s[k+1] == s[k]) {
                s.erase(s.begin()+k+1);
                s.erase(s.begin()+k);
                k = max(0, k-1);
            } else {
                k++;
            }
        }

        return s.size() == 0 || s.size() == 1;
    }
};
