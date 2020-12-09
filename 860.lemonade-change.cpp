// CreateTime: 2020-12-10 03:28:04
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f5 = 0;
        int f10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            auto x = bills[i];

            if (x == 5) {
                f5++;
            }

            else if (x == 10) {
                f5--;
                f10++;
            }

            else if (x == 20) {
                if (f10 > 0) {
                    f5--;
                    f10--;
                } else {
                    f5 -= 3;
                }
            }

            if (f5 < 0 || f10 < 0) {
                return false;
            }
        }

        return true;
    }
};
