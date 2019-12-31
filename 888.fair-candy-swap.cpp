// CreateTime: 2019-12-31 17:51:16
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum1 = 0;
        int sum2 = 0;
        
        unordered_set<int> bs;

        for (int i = 0; i < A.size(); i++) {
            sum1 += A[i];
        }
        
        for (int i = 0; i < B.size(); i++) {
            sum2 += B[i];
            bs.insert(B[i]);
        }
        
        int avg = (sum1+sum2)/2;
        if (sum1 > avg) {
            for (int i = 0; i < A.size(); i++) {
                if (bs.find(A[i]-(sum1-avg)) != bs.end()) {
                    return {A[i], A[i]-(sum1-avg)};
                }
            }
        } else {
            for (int i = 0; i < A.size(); i++) {
                if (bs.find(A[i]+(avg-sum1)) != bs.end()) {
                    return {A[i], A[i]+(avg-sum1)};
                }
            }
        }

        return {-1, -1};
    }
};
