// CreateTime: 2021-01-31 10:30:30
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;

        int ans = 0;
        for (int i = lowLimit; i <= highLimit; i++) {
            int s = 0;
            for (auto &x: to_string(i)) {
                s += x-'0';
            }
            m[s]++;

            ans = max(ans, m[s]);
        }
        return ans;
    }
};