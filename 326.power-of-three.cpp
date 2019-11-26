// CreateTime: 2019-11-26 23:06:09
class Solution {
public:
    bool isPowerOfThree(int n) {
        unordered_set<int> m;
        m.insert(1);
        
        int v = 1;
        for (int i = 1; i <= 19 && v*3 <= n; i++) {
            v = v * 3;
            m.insert(v);
        }
        
        return m.find(n) != m.end();
    }
};
