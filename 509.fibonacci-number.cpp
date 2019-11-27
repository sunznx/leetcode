// CreateTime: 2019-11-27 15:32:44
class Solution {
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }

        int a = 0;
        int b = 1;
        int res;
        for (int i = 2; i <= N; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        
        return res;
    }
};