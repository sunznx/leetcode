// CreateTime: 2020-01-02 09:56:16
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int len = arr.size();
        auto avg = len/4;
        
        unordered_map<int, int> m;
        for (int i = 0; i < len; i++) {
            m[arr[i]] += 1;
            if (m[arr[i]] > avg) {
                return arr[i];
            }
        }
        
        return -1;
    }
};
