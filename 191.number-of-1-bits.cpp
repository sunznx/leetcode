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

    uint32_t lowbit(uint32_t n) {
        return (n & (n -1));
    }
};
