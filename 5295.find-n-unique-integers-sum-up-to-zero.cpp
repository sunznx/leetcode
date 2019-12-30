// CreateTime: 2019-12-30 09:50:20
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        
        int k = 0; 
        
        if (n % 2 == 1) {
            res[k++] = 0;
        }
        
        for (int i = n/2; i >= 1; i--) {
            res[k++] = i;
            res[k++] = -i;
        }

        return res;
    }
};
