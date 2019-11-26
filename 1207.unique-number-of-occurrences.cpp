// CreateTime: 2019-11-26 01:34:53
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_map<int, int> c;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] += 1;
        }
        for (auto item: m) {
            c[item.second] += 1;
            if (c[item.second] > 1) {
                return false;
            }
        }

        return true;
    }
};
