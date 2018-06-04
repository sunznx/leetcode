class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while (n) {
            n = lowbit(n);
            count++;
        }

        return count;
    }

    int lowbit(int n) {
        return (n & (n -1));
    }
};
