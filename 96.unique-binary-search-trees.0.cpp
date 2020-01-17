// CreateTime: 2020-01-17 08:27:09
class Solution {
public:
    int numTrees(int n) {
        long C = 1;
        for (int i = 1; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
