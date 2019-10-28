class Solution {
public:
    int integerReplacement(int n) {
        if (n <= 1) {
            return 0;
        }

        if (n % 2 == 0) {
            return integerReplacement(n/2) + 1;
        }

        int n1 = ((unsigned int)(n) + 1)/2;
        int n2 = ((unsigned int)(n) - 1)/2;
        int res1 = integerReplacement(n1);
        int res2 = integerReplacement(n2);
        return min(res1, res2) + 2;
    }
};
