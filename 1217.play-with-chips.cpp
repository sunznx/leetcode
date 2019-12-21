// CreateTime: 2019-12-21 09:25:40
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int len = chips.size();
        
        int even = 0;
        int odd = 0;
        
        for (int i = 0; i < len; i++) {
            if (chips[i] % 2 == 0) {
                even += 1;
            } else {
                odd += 1;
            }
        }
        
        return min(even, odd);
    }
};
