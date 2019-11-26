// CreateTime: 2019-11-26 23:06:09
class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_map<int, int> m;
        m[1] = 0;
        
        int v = 1;
        for (int i = 1; i <= 19 && v*3 <= n; i++) {
            m[v*3] = i;
            v = v * 3;
        }
        
        return m.find(n) != m.end();
    }
};
