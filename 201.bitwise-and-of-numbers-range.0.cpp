// CreateTime: 2021-03-22 20:04:24
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right = (right & (right-1));
        }
        return right;
    }
};
