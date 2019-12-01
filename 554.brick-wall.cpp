// CreateTime: 2019-12-01 14:16:15
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int len = wall.size();
        int ans = len;

        unordered_map<int, int> m;
        for (int i = 0; i < len; i++) {
            
            for (int j = 0; j < wall[i].size()-1; j++) {
                if (j > 0) {
                    wall[i][j] = wall[i][j-1] + wall[i][j];                    
                }
                m[wall[i][j]] += 1;
                ans = min(ans, len-m[wall[i][j]]);
            }
        }
        
        return ans;
    }
};
