// CreateTime: 2020-11-22 02:13:20
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();

        stack<pair<int, int>> s;
        vector<int> ans(len);
        
        for (int i = len-1; i >= 0; i--) {
            auto num = T[i];
            
            while (s.size() && num >= s.top().second) {
                s.pop();
            }
            
            if (s.size() == 0) {
                ans[i] = 0;
            } else {
                ans[i] = s.top().first - i;
            }
            
            s.push({i, num});
        }
        
        return ans;
    }
};
