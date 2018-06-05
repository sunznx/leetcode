class Solution {
public:
    int getSum(int a, int b) {
        int res = (a ^ b);
        int carry = ((a & b) << 1);
        if (carry) {
            return getSum(res, carry);
        }

        return res;
    }
};
