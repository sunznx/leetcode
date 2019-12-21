// CreateTime: 2019-11-22 16:29:33
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0;
        int cnt10 = 0;
        
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 20) {
                if (cnt10 > 0) {
                    cnt10 -= 1;
                    cnt5 -= 1;                    
                } else {
                    cnt5 -= 3;
                }
            }
            if (bills[i] == 5) {
                cnt5++;
            }
            if (bills[i] == 10) {
                cnt5 -= 1;
                cnt10++;
            }
            
            if (cnt10 < 0 || cnt5 < 0) {
                return false;
            }
        }
        return true;
    }
};
