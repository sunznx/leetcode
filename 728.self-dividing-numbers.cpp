class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        
        for (int i = left; i <= right; i++) {
            int num = i;
            int ok = 1;
            
            while (num != 0) {
                int p = num % 10;
                num = num / 10;
                
                if (p == 0) {
                    ok = 0;
                    break;
                }
                
                if (i % p != 0) {
                    ok = 0;
                    break;
                }
            }
            
            if (ok) {
                v.push_back(i);
            }
        }
        
        return v;
    }
};
