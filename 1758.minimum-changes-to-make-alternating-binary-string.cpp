// CreateTime: 2021-02-14 02:31:10
class Solution {
public:
    int minOperations(string s) {
        int sub1 = 0;
        int sub2 = 0;
        char k;

        k = '0';
        for (auto &x: s) {
            if (x != k) {
                sub1++;
            }

            k = toggleChar(k);
        }

        k = '1';
        for (auto &x: s) {
            if (x != k) {
                sub2++;
            }

            k = toggleChar(k);
        }

        return min(sub1, sub2);
    }

    char toggleChar(char k) {
        if (k == '0') {
            return '1';
        }
        return '0';
    }
};