// CreateTime: 2019-11-26 23:23:17
class Solution {
public:
    bool isPowerOfFour(int num) {
        unordered_set<int> m;
        
        m.insert(1);
        int v = 1;
        for (int i = 1; i <= 15; i++) {
            v = v * 4;
            m.insert(v);
        }
        
        return m.find(num) != m.end();
    }
};
