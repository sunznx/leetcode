// CreateTime: 2020-11-25 12:50:27
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = getMax(piles);
        
        while (l < r) {
            int m = (l+r) / 2;
            
            if (check(piles, H, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
    
    int getMax(vector<int>& piles) {
        int ans = 1;
        int len = piles.size();
        for (int i = 0; i < len; i++) {
            ans = max(ans, piles[i]);
        }
        return ans;
    }

    bool check(vector<int>& piles, int H, int speed) {
        int len = piles.size();
        int need = 0;
        for (int i = 0; i < len; i++) {
            need += timeOf(piles[i], speed);
        }
        return need <= H;
    }
    
    int timeOf(int pile, int speed) {
        return pile / speed + (int)(pile % speed != 0);
    }
};
