// CreateTime: 2019-11-26 14:28:47
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        
        sort(arr.begin(), arr.end());

        int len = arr.size();
        int minv = arr[len-1]-arr[0];

        for (int i = 1; i < len; i++) {
            auto first = arr[i-1];
            auto second = arr[i];
            minv = min(minv, second-first);
        }
        
        for (int i = 1; i < len; i++) {
            auto first = arr[i-1];
            auto second = arr[i];

            if (second-first == minv) {
                res.push_back({first, second});
            }
        }

        return res;
    }
};
