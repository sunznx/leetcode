class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) {
            return false;
        }
        
        if (num == 1) {
            return true;
        }
        
        int L = 1;
        int R = num;
        
        while (L <= R) {
            long mid = (R + L) / 2;
            
            if (mid * mid ==  num) {
                return true;
            } else if (mid * mid > num) {
                R = mid - 1;
            } else if (mid * mid < num) {
                L = mid + 1;
            }
        }
        
        return false;
    }
};
