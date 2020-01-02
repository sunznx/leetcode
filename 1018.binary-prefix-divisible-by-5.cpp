// CreateTime: 2020-01-02 14:18:39
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int len = A.size();
        vector<bool> res(len);
        
        int v = 0;

        for (int i = 0; i < len; i++) {
            v = (v*2 + A[i]) % 10;
            if (v % 5 == 0) {
                res[i] = true;
            } else {
                res[i] = false;
            }
        }

        return res;
    }
};
