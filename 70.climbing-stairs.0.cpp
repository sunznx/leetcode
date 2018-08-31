class Solution {
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        for (int i = 2; i <= n; i++) {
            int t = one;
            one = two;
            two = t + two;
        }

        return two;
    }
};
