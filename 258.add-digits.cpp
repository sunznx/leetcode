class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int res = 0;
            while (num) {
                int mod = num % 10;
                num = num / 10;
                res = res + mod;
            }
            num = res;
        }
        
        return num;
    }
};
