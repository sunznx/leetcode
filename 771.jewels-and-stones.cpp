class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int len1 = J.size();
        int len2 = S.size();

        if (len1 == 0) {
            return 0;
        }

        int strmap[256] = {0};

        for (int i = 0; i < len1; i++) {
            strmap[J[i]] = 1;
        }

        int res = 0;
        for (int i = 0; i < len2; i++) {
            if (strmap[S[i]]) {
                res++;
            }
        }

        return res;
    }
};
