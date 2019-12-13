// CreateTime: 2019-12-13 19:01:26
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int mul = 1;
        while (n) {
            int m = n % 10;
            n = n / 10;
            sum += m;
            mul *= m;
        }
        
        return mul - sum;
    }
};
