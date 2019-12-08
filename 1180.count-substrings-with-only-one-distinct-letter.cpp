// CreateTime: 2019-12-09 07:03:12
class Solution {
public:
    int countLetters(string S) {
        int res = 0;

        int len = S.size();
        int cnt = 0;
        
        for (int i = 0; i < len; i++) {
            cnt += 1;
            if (i == len-1 || S[i] != S[i+1]) {
                res += (cnt) * (cnt+1) / 2;
                cnt = 0;
            }
        }
        
        return res;
    }
};
