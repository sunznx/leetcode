class Solution {
public:
    unordered_map<int, int> m;

    int integerReplacement(int n) {
        if (m.find(n) != m.end()) {
            return m[n];
        }

        if (n <= 1) {
            return m[n] = 0;
        }

        if (n % 2 == 0) {
            return m[n] = integerReplacement(n/2) + 1;
        }

        int n1 = ((unsigned int)(n) + 1)/2;
        int n2 = ((unsigned int)(n) - 1)/2;
        m[n1] = integerReplacement(n1);
        m[n2] = integerReplacement(n2);
        return m[n] = min(m[n1], m[n2]) + 2;
    }
};
