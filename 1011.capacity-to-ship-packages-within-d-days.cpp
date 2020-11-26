// CreateTime: 2020-11-25 13:49:19
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 0;
        int r = 0;
        
        int len = weights.size();
        for (int i = 0; i < len; i++) {
            r = r + weights[i];
            l = max(l, weights[i]);
        }

        while (l < r) {
            int m = (l+r) / 2;
            if (check(weights, D, m)) {
                r = m;
            } else {
                l = m+1;
            }
        }
        return l;
    }
    
    bool check(vector<int>& weights, int D, int w) {
        int need = 0;
        int len = weights.size();
        
        int reserve = 0;
        for (int i = 0; i < len; i++) {
            if (reserve < weights[i]) {
                reserve = w;
                need++;
            }
            reserve -= weights[i];
        }
        return need <= D;
    }
};
