class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5 = 0;
        int num_10 = 0;

        int len = bills.size();
        for (int i = 0; i < len; i++) {
            if (bills[i] == 5) {
                num_5 += 1;
            } else if (bills[i] == 10) {
                if (num_5 == 0) {
                    return false;
                }
                num_5 -= 1;
                num_10 += 1;
            } else if (bills[i] == 20) {
                if (num_10 >= 1 && num_5 >= 1) {
                    num_5 -= 1;
                    num_10 -= 1;
                } else if (num_10 == 0 && num_5 >= 3) {
                    num_5 -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
