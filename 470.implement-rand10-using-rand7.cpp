// CreateTime: 2021-03-15 22:37:15
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (true) {
            int k1 = rand7();
            int k2 = rand7();
            
            int k = (k1-1) * 7+ k2;
            
            if (k > 40) {
                continue;
            }
            
            return k % 10 + 1;
        }
        return -1;
    }
};
