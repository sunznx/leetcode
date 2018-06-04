class Solution {
public:
    int findComplement(int num) {
        int p = num;
        while (1) {
            int tmp = lowbit(p);
            if (p == tmp) {
                break;
            }
            p -= tmp;
        }
        p -= 1;
        return (-num - 1) & p;
    }

    int lowbit(int num) {
        return num & (-num);
    }
};
