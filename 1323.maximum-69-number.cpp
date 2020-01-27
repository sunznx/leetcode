// CreateTime: 2020-01-28 00:23:25
class Solution {
public:
    int maximum69Number (int num) {
        int res = num;
        int p = 1;
        int v = num;
        while (v) {
            int m = v % 10;
            v = v / 10;
            if (m == 6) {
                res = num + 3 * p;
            }
            p = p * 10;
        }

        return res;
    }
};
