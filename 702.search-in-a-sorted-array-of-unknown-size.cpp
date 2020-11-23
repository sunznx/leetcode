// CreateTime: 2020-11-24 07:48:24
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        const int invalidNum = 2147483647;
        
        const int len = 20000;
        
        int l = 0;
        int r = len;
        
        while (l < r) {
            int m = (l+r) / 2;
            
            auto x = reader.get(m);
            if (x == invalidNum) {
                r = m-1;
            } else if (target > x) {
                l = m+1;
            } else if (target <= x) {
                r = m;
            }
        }
        
        if (reader.get(l) == target) {
            return l;
        }
        return -1;
    }
};
