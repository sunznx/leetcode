class Solution {
public:
    int bitwiseComplement(int N) {
        int ans = 0;
        int cnt = 0;
        int MAXBIT = 1;
        int T;

        T = N;
        while (T) {
            MAXBIT = max(MAXBIT, lowbit(T));
        }

        T = ~N;
        while (true) {
            int t = lowbit(T);
            if (t > MAXBIT) {
                break;
            }
            ans += t;
        }
        return ans;
    }

    inline int lowbit(int &N) {
        unsigned int T = N;
        int res = N & (-T);
        N -= res;
        return res;
    }
};

