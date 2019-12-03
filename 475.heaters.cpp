// CreateTime: 2019-11-28 16:12:18
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        const int inf = 0x7fffffff;
        
        heaters.push_back(-inf);
        heaters.push_back(inf);
        sort(heaters.begin(), heaters.end());

        int ans = 0;
        int len = houses.size();
        for (int i = 0; i < len; i++) {
            int l = 0;
            int r = heaters.size()-1;
            
            while (l < r) {
                int mid = (l+r) / 2;
                if (heaters[mid] < houses[i]) {
                    l = mid+1;
                } else if (heaters[mid] >= houses[i]) {
                    r = mid;
                }
            }
            
            ans = max(ans, (int)min(heaters[l]-0ll-houses[i], houses[i]-0ll-heaters[l-1]));
        }
        
        return ans;
    }
};

